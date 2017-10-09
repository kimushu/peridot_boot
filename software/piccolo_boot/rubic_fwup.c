/**
 * @file rubic_fwup.c
 * @brief Self firmware updater for Rubic
 */

#include "rubic_fwup.h"
#include "rubic_fwup_msg.h"
#include <errno.h>
#include <string.h>
#include <sys/fcntl.h>
#include <sys/stat.h>
#include "peridot_swi.h"
#include <stdint.h>

static uint32_t crc32_table[256];

static void crc32_init(void)
{
    int i;
    for (i = 0; i < 256; ++i) {
        uint32_t c = i;
        int j;
        for (j = 0; j < 8; ++j) {
            c = (c & 1) ? (0xedb88320 ^ (c >> 1)) : (c >> 1);
        }
        crc32_table[i] = c;
    }
}

static uint32_t crc32(void *ptr, int len){
    uint32_t c = 0xffffffff;
    uint8_t *buf = (uint8_t *)ptr;
    int i;
    for (i = 0; i < len; ++i)    {
        c = crc32_table[(c ^ *buf++) & 0xff] ^ (c >> 8);
    }
    return c ^ 0xffffffff;
}

static const rubic_fwup_memory *find_memory(const rubic_fwup_memory *memories, const char *name)
{
    const rubic_fwup_memory *mem;
    for (mem = memories; mem->name; ++mem) {
        if (memcmp(mem->name, name, 3) == 0) {
            return mem;
        }
    }
    errno = ESRCH;
    return NULL;
}

static int read_memory(const rubic_fwup_memory *mem, rubic_fwup_msg_read *msg)
{
    rubic_fwup_res_read *res = (rubic_fwup_res_read *)msg;
    int fd;
    struct stat st;
    int read_len;

    if (!mem) {
        return -ENODEV;
    }
    if ((fd = open(mem->path, O_RDONLY)) < 0) {
        return -ENOENT;
    }
    if (fstat(fd, &st) < 0) {
        close(fd);
        return -EIO;
    }
    size_t mem_end = mem->offset + ((mem->length < 0) ? st.st_size : mem->length);
    size_t abs_offset = msg->offset + mem->offset;
    size_t abs_end = (msg->length < 0) ? mem_end : (abs_offset + msg->length);
    if (abs_offset >= mem_end) {
        close(fd);
        return -ERANGE;
    }
    if (abs_end > mem_end) {
        abs_end = mem_end;
    }
    if ((lseek(fd, abs_offset, SEEK_SET) != abs_offset) ||
        ((read_len = read(fd, res->data, abs_end - abs_offset)) < 0)) {
        close(fd);
        return -EIO;
    }
    close(fd);

    res->signature[0] = 'r';
    memcpy(res->signature + 1, mem->name, 3);
    res->length = read_len;
    res->sector_size = st.st_blksize;
    memcpy(res->data + read_len, "\0\0\0", 3);
    res->hash = crc32(&res->data[0], read_len);
    return sizeof(*res) + read_len;
}

static int hash_memory(const rubic_fwup_memory *mem, rubic_fwup_msg_hash *msg)
{
    rubic_fwup_res_hash *res = (rubic_fwup_res_hash *)msg;
    int fd;
    struct stat st;
    alt_u32 *hash;

    if (!mem) {
        return -ENODEV;
    }
    if ((fd = open(mem->path, O_RDONLY)) < 0) {
        return -ENOENT;
    }
    if (fstat(fd, &st) < 0) {
        close(fd);
        return -EIO;
    }
    size_t mask = st.st_blksize - 1;
    size_t mem_end = (mem->offset + ((mem->length < 0) ? st.st_size : mem->length)) & ~mask;
    size_t abs_offset = (msg->offset + mem->offset) & ~mask;
    size_t abs_end = (msg->length < 0) ? mem_end : ((abs_offset + msg->length + mask) & ~mask);
    if (abs_offset >= mem_end) {
        close(fd);
        return -ERANGE;
    }
    if (abs_end > mem_end) {
        abs_end = mem_end;
    }
    if (lseek(fd, abs_offset, SEEK_SET) != abs_offset) {
        close(fd);
        return -EIO;
    }
    hash = res->hash;
    res->length = abs_end - abs_offset;
    for (; abs_offset < abs_end; abs_offset += st.st_blksize, ++hash) {
        if (read(fd, hash, st.st_blksize) != st.st_blksize) {
            close(fd);
            return -EIO;
        }
        *hash = crc32(hash, st.st_blksize);
    }
    close(fd);

    res->signature[0] = 'h';
    memcpy(res->signature + 1, mem->name, 3);
    res->sector_size = st.st_blksize;
    return ((size_t)hash - (size_t)res);
}

static int write_memory(const rubic_fwup_memory *mem, rubic_fwup_msg_write *msg)
{
    rubic_fwup_res_write *res = (rubic_fwup_res_write *)msg;
    rubic_fwup_msg_write_entry *ent;
    int fd;
    struct stat st;
    int result;
    alt_u32 address;

    if (!mem) {
        return -ENODEV;
    }
    if ((fd = open(mem->path, O_WRONLY)) < 0) {
        return -ENOENT;
    }
    if (fstat(fd, &st) < 0) {
        close(fd);
        return -EIO;
    }
    size_t mem_end = mem->offset + ((mem->length < 0) ? st.st_size : mem->length);

    result = 0;
    address = 0;
    ent = msg->entries;
    for (;;) {
    	alt_u32 actual;

        if (ent->length == 0) {
        	break;
        }

        address = ent->offset;

    	actual = crc32(&ent->data[0], ent->length);
        if (actual != ent->hash) {
            result = EILSEQ;
            break;
        }

        size_t abs_offset = ent->offset + mem->offset;
        size_t abs_end = abs_offset + ent->length;
        if ((abs_offset >= mem_end) || (abs_end > mem_end)) {
            result = ERANGE;
            break;
        }
        if (lseek(fd, abs_offset, SEEK_SET) != abs_offset) {
            result = EIO;
            break;
        }
        int written_len;
        if ((written_len = write(fd, ent->data, ent->length)) < 0) {
            result = (errno == 0) ? EIO : errno;
            break;
        }
        if (written_len != ent->length) {
            result = EIO;
            address += written_len;
            break;
        }
        ent = (rubic_fwup_msg_write_entry *)(((uint8_t *)(ent + 1)) + ((ent->length + 3) & ~3));
    }

    res->signature[0] = 'w';
    memcpy(res->signature + 1, mem->name, 3);
    res->result = result;
    res->address = (result == 0) ? ~0 : address;
    close(fd);
    return sizeof(*res);
}

int rubic_fwup_service(uintptr_t message_addr, size_t message_size, const rubic_fwup_memory *memories)
{
    rubic_fwup_response *res = (rubic_fwup_response *)(message_addr | (1<<31));
    rubic_fwup_message *msg = (rubic_fwup_message *)res;

    peridot_swi_write_message(0);

    crc32_init();

    memcpy(res->boot.signature, "boot", 4);
    res->boot.capacity = message_size;

    for (;;) {
        int result;

        // Send response
        peridot_swi_write_message(message_addr);

        // Wait for new message
        for (;;) {
            alt_u32 msg;
            if ((peridot_swi_read_message(&msg) == 0) && (msg == 0)) {
                break;
            }
        }

        // Process message
        result = ESRCH;
        if (memcmp(msg->signature, "Stop", 4) == 0) {
            // Stop service
        	memcpy(res->error.signature, "----", 4);
        	res->error.result = 0;
        	res->error.capacity = 0;
            peridot_swi_write_message(message_addr);
            break;
        } else if (msg->signature[0] == 'R') {
            // Read memory
            result = read_memory(find_memory(memories, msg->signature + 1), &msg->read);
        } else if (msg->signature[0] == 'H') {
            // Hash check of memory
            result = hash_memory(find_memory(memories, msg->signature + 1), &msg->hash);
        } else if (msg->signature[0] == 'W') {
            // Write memory
            result = write_memory(find_memory(memories, msg->signature + 1), &msg->write);
        }

        res->error.capacity = message_size;
        if (result < 0) {
            // Unknown
            memcpy(res->error.signature, "err_", 4);
            res->error.result = -result;
        }
    }

    return 0;
}
