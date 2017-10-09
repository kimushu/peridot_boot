/**
 * @file rubic_fwup_msg.h
 * @brief Message structure definitions for rubic_fwup
 */

#ifndef __RUBIC_FWUP_MSG_H__
#define __RUBIC_FWUP_MSG_H__

#include <unistd.h>
#include "alt_types.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    char signature[4];  // xxxx
    size_t capacity;
} rubic_fwup_res_boot;

typedef struct {
    char signature[4];  // Rxxx
    ssize_t length;
    size_t offset;
} rubic_fwup_msg_read;

typedef struct {
    char signature[4];  // rxxx
    size_t capacity;
    size_t length;
    size_t sector_size;
    alt_u32 hash;
    alt_u8 data[0];
} rubic_fwup_res_read;

typedef struct {
    char signature[4];  // Hxxx
    ssize_t length;
    size_t offset;
} rubic_fwup_msg_hash;

typedef struct {
    char signature[4];  // hxxx
    size_t capacity;
    size_t length;
    size_t sector_size;
    alt_u32 hash[0];
} rubic_fwup_res_hash;

typedef struct {
    size_t length;
    size_t offset;
    alt_u32 hash;
    alt_u8 data[0];
} rubic_fwup_msg_write_entry;

typedef struct {
    char signature[4];  // Wxxx
    rubic_fwup_msg_write_entry entries[0];
} rubic_fwup_msg_write;

typedef struct {
    char signature[4];  // wxxx
    size_t capacity;
    int result;
    alt_u32 address;
} rubic_fwup_res_write;

typedef struct {
    char signature[4];  // Stop
} rubic_fwup_msg_stop;

typedef struct {
    char signature[4];  // err_
    size_t capacity;
    int result;
} rubic_fwup_res_error;

typedef union {
    rubic_fwup_res_boot boot;
    rubic_fwup_res_read read;
    rubic_fwup_res_hash hash;
    rubic_fwup_res_write write;
    rubic_fwup_res_error error;
} rubic_fwup_response;

typedef union {
    char signature[4];
    rubic_fwup_msg_read read;
    rubic_fwup_msg_hash hash;
    rubic_fwup_msg_write write;
    rubic_fwup_msg_stop stop;
} rubic_fwup_message;

#ifdef __cplusplus
}   /* extern "C" */
#endif

#endif  /* __RUBIC_FWUP_MSG_H__ */
