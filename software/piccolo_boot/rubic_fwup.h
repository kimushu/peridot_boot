/**
 * @file rubic_fwup.h
 * @brief Self firmware updater for Rubic
 */

#ifndef __RUBIC_FWUP_H__
#define __RUBIC_FWUP_H__

#include <stddef.h>
#include <stdint.h>
#include <unistd.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct rubic_fwup_memory_s {
    const char *name;
    const char *path;
    size_t offset;
    ssize_t length;
} rubic_fwup_memory;

extern int rubic_fwup_service(uintptr_t message_addr, size_t message_size, const rubic_fwup_memory *memories);

#ifdef __cplusplus
}   /* extern "C" */
#endif

#endif  /* __RUBIC_FWUP_H__ */
