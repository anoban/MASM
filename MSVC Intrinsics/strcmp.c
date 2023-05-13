#include <immintrin.h>
#include <stdint.h>
#include <stdalign.h>
#include <stdio.h>

typedef union {

    alignas(64) int8_t		mi8[64];
    alignas(64) int16_t		mi16[32];
    alignas(64) int32_t		mi32[16];
    alignas(64) int64_t		mi64[8];

    alignas(64) uint8_t		mu8[64];
    alignas(64) uint16_t	mu16[32];
    alignas(64) uint32_t	mu32[16];
    alignas(64) uint64_t	mu64[8];

    alignas(64) float		mf32[16];
    alignas(64) double		mf64[8];

} zmm_t;

int main(void) {

    __mmask64 cmp_res = 0;
    zmm_t string = { .mi8 {} };

    __m512 array_1 = (__m512)


}