#pragma once
#include <stdint.h>
#include <stdalign.h>
#include <immintrin.h>

typedef union {
	
	alignas(16) int8_t  i8[16];
	alignas(16) int16_t i16[8];
	alignas(16) int32_t i32[4];
	alignas(16) int64_t i64[2];

	alignas(16) uint8_t  u8[16];
	alignas(16) uint16_t u16[8];
	alignas(16) uint32_t u32[4];
	alignas(16) uint64_t u64[2];

	alignas(16) float f32[4];
	alignas(16) long double f64[2];

} xmm_t;	// 128 bits

typedef union {
	
	alignas(32)  int8_t  i8[32];
	alignas(32)  int16_t i16[16];
	alignas(32)  int32_t i32[8];
	alignas(32)  int64_t i64[4];

	alignas(32)  uint8_t  u8[32];
	alignas(32)  uint16_t u16[16];
	alignas(32)  uint32_t u32[8];
	alignas(32)  uint64_t u64[4];

	alignas(32)  float f32[8];
	alignas(32)  long double f64[4];

} ymm_t;	// 256 bits

typedef union {
	
	alignas(64)   int8_t  i8[64];
	alignas(64)   int16_t i16[32];
	alignas(64)   int32_t i32[16];
	alignas(64)   int64_t i64[8];

	alignas(64)   uint8_t  u8[64];
	alignas(64)   uint16_t u16[32];
	alignas(64)   uint32_t u32[16];
	alignas(64)   uint64_t u64[8];

	alignas(64)   float f32[16];
	alignas(64)   long double f64[8];

} zmm_t;	// 512 bits