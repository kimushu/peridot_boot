#include "crc32.h"

static uint32_t crc32_table[256];

void crc32_init(void)
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

void crc32_calc(crc32hash_t *result, const void *ptr, int len)
{
    crc32hash_t c = 0xffffffff;
    const uint8_t *buf = (const uint8_t *)ptr;
    int i;
    for (i = 0; i < len; ++i)    {
        c = crc32_table[(c ^ *buf++) & 0xff] ^ (c >> 8);
    }
    *result = (c ^ 0xffffffff);
}
