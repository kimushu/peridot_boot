#ifndef __CRC32_H__
#define __CRC32_H__

#include <stdint.h>

typedef uint32_t crc32hash_t;

extern void crc32_init(void);
extern void crc32_calc(crc32hash_t *result, const void *ptr, int len);

#endif  /* __CRC32_H__ */
