#include <stdint.h>
#include <stdalign.h>

typedef union {
	// A union to represent values stored in an xmm register.
	// (a 128 bits wide register)

	// One such register can hold either of these following arrays.

	alignas(16) int8_t		mi8[16];
	alignas(16) int16_t		mi16[8];
	alignas(16) int32_t		mi32[4];
	alignas(16) int64_t		mi64[2];

	alignas(16) uint8_t		mu8[16];
	alignas(16) uint16_t	mu16[8];
	alignas(16) uint32_t	mu32[4];
	alignas(16) uint64_t	mu64[2];

	alignas(16) float		mf32[4];
	alignas(16) double		mf64[2];

} xmm_t;
