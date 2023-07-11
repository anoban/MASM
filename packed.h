#pragma once
#include <stdalign.h>
#include <stdint.h>
#include <immintrin.h>

// A union of packed arrays (16 bytes or 128 bits) different types.
typedef union {

    alignas(16) int8_t i8[16];
    alignas(16) uint8_t u8[16];

    alignas(16) int16_t i16[8];
    alignas(16) uint16_t u16[8];

    alignas(16) int32_t i32[4];
    alignas(16) uint32_t u32[4];

    alignas(16) int64_t i64[2];
    alignas(16) uint64_t u64[2];

    alignas(16) float f32[4];
    alignas(16) long double f64[2];

} xmm_t;