#ifndef __MD5_H__
#define __MD5_H__

#include <stdint.h>

typedef struct {
    uint32_t words[4];
} md5hash_t;

extern void md5_init(void);
extern void md5_calc(md5hash_t *result, const void *ptr, int len);

#endif  /* __MD5_H__ */
