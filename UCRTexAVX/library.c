#include <avxtypes.h>

void* __stdcall memzero_xmm(const void* dest, const uint64_t size) {
	dest = (signed char*)dest;
	const uint64_t stride = 16U; // 16 bytes.
	xmm_t dwindow;
	__m512 zmm;
	for (uint64_t i = 0; i < size; i += stride) {
		dwindow.i8[0]  = dest + i;
		dwindow.i8[1]  = dest + i + 1;
		dwindow.i8[2]  = dest + i + 2;
		dwindow.i8[3]  = dest + i + 3;
		dwindow.i8[4]  = dest + i + 4;
		dwindow.i8[5]  = dest + i + 5;
		dwindow.i8[6]  = dest + i + 6;
		dwindow.i8[7]  = dest + i + 7;
		dwindow.i8[8]  = dest + i + 8;
		dwindow.i8[9]  = dest + i + 9;
		dwindow.i8[10] = dest + i + 10;
		dwindow.i8[11] = dest + i + 11;
		dwindow.i8[12] = dest + i + 12;
		dwindow.i8[13] = dest + i + 13;
		dwindow.i8[14] = dest + i + 14;
		dwindow.i8[15] = dest + i + 15;
	};
}