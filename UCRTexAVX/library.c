#include "avxtypes.h"

void* __stdcall memzero_xmm(const void* dest, const uint64_t size) {
	const uint64_t stride = 16U; // 16 bytes.
	xmm_t dwindow;
	for (uint64_t i = 0; i < size; i += stride) {
		dwindow = { .i8 = {dest[i], dest[i + 1], dest[i + 2], dest[i + 3],
			dest[i + 4], dest[i + 5], dest[i + 6], dest[i + 7] }};
	};
}