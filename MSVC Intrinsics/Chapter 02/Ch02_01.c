#include "xmmval.h"
#include <stdio.h>
#include <immintrin.h>

void addI16_avx(xmm_t* c1, xmm_t* c2, const xmm_t* a, const xmm_t* b) {

	__m128i _a = _mm_load_si128((__m128i*) a);
	__m128i _b = _mm_load_si128((__m128i*) b);

	__m128i _c1 = _mm_add_epi16(_a, _b);
	__m128i _c2 = _mm_adds_epi16(_a, _b);

	_mm_store_si128((__m128i*) c1, _c1);
	_mm_store_si128((__m128i*) c2, _c2);

}

void addU16_avx(xmm_t* c1, xmm_t* c2, const xmm_t* a, const xmm_t* b) {

	__m128i _a = _mm_load_si128((__m128i*) a);
	__m128i _b = _mm_load_si128((__m128i*) b);

	__m128i _c1 = _mm_add_epi16(_a, _b);
	__m128i _c2 = _mm_adds_epu16(_a, _b);

	_mm_store_si128((__m128i*) c1, _c1);
	_mm_store_si128((__m128i*) c2, _c2);

}

static void addI16C(void) {

	xmm_t rw = { .mi16 = {0} }, rs = { .mi16 = {0} };
	const xmm_t a = { .mi16 = {10, 200, 30, -32766, 50, 60, 32000, -32000} };
	const xmm_t b = { .mi16 = {100, -200, 32760, -400, 500, -600, 1200, -950} };

	addI16_avx(&rw, &rs, &a, &b);

	puts("Results for addI16_avx wraparound addition");
	printf_s("Input 1: [%8hd, %8hd, %8hd, %8hd, %8hd, %8hd, %8hd, %8hd]\n",
		a.mi16[0], a.mi16[1], a.mi16[2], a.mi16[3], a.mi16[4], a.mi16[5], a.mi16[6], a.mi16[7]);
	printf_s("Input 2: [%8hd, %8hd, %8hd, %8hd, %8hd, %8hd, %8hd, %8hd]\n",
		b.mi16[0], b.mi16[1], b.mi16[2], b.mi16[3], b.mi16[4], b.mi16[5], b.mi16[6], b.mi16[7]);
	printf_s("Result:  [%8hd, %8hd, %8hd, %8hd, %8hd, %8hd, %8hd, %8hd]\n",
		rw.mi16[0], rw.mi16[1], rw.mi16[2], rw.mi16[3], rw.mi16[4], rw.mi16[5], rw.mi16[6], rw.mi16[7]);
	puts("");

	puts("Results for addI16_avx saturated addition");
	printf_s("Input 1: [%8hd, %8hd, %8hd, %8hd, %8hd, %8hd, %8hd, %8hd]\n",
		a.mi16[0], a.mi16[1], a.mi16[2], a.mi16[3], a.mi16[4], a.mi16[5], a.mi16[6], a.mi16[7]);
	printf_s("Input 2: [%8hd, %8hd, %8hd, %8hd, %8hd, %8hd, %8hd, %8hd]\n",
		b.mi16[0], b.mi16[1], b.mi16[2], b.mi16[3], b.mi16[4], b.mi16[5], b.mi16[6], b.mi16[7]);
	printf_s("Result:  [%8hd, %8hd, %8hd, %8hd, %8hd, %8hd, %8hd, %8hd]\n",
		rs.mi16[0], rs.mi16[1], rs.mi16[2], rs.mi16[3], rs.mi16[4], rs.mi16[5], rs.mi16[6], rs.mi16[7]);
	puts("");
}

static void addU16C(void) {

	xmm_t rw = { .mu16 = {0} }, rs = { .mu16 = {0} };
	const xmm_t a = { .mu16 = {10, 200, 300, 32766, 50, 60, 32000, 32000} };
	const xmm_t b = { .mu16 = {100, 200, 65530, 40000, 500, 25000, 1200, 50000} };

	addU16_avx(&rw, &rs, &a, &b);

	puts("Results for addU16_avx wraparound addition");
	printf_s("Input 1: [%8hd, %8hd, %8hd, %8hd, %8hd, %8hd, %8hd, %8hd]\n",
		a.mu16[0], a.mu16[1], a.mu16[2], a.mu16[3], a.mu16[4], a.mu16[5], a.mu16[6], a.mu16[7]);
	printf_s("Input 2: [%8hd, %8hd, %8hd, %8hd, %8hd, %8hd, %8hd, %8hd]\n",
		b.mu16[0], b.mu16[1], b.mu16[2], b.mu16[3], b.mu16[4], b.mu16[5], b.mu16[6], b.mu16[7]);
	printf_s("Result:  [%8hd, %8hd, %8hd, %8hd, %8hd, %8hd, %8hd, %8hd]\n",
		rw.mu16[0], rw.mu16[1], rw.mu16[2], rw.mu16[3], rw.mu16[4], rw.mu16[5], rw.mu16[6], rw.mu16[7]);
	puts("");

	puts("Results for addU16_avx saturated addition");
	printf_s("Input 1: [%8hd, %8hd, %8hd, %8hd, %8hd, %8hd, %8hd, %8hd]\n",
		a.mu16[0], a.mu16[1], a.mu16[2], a.mu16[3], a.mu16[4], a.mu16[5], a.mu16[6], a.mu16[7]);
	printf_s("Input 2: [%8hd, %8hd, %8hd, %8hd, %8hd, %8hd, %8hd, %8hd]\n",
		b.mu16[0], b.mu16[1], b.mu16[2], b.mu16[3], b.mu16[4], b.mu16[5], b.mu16[6], b.mu16[7]);
	printf_s("Result:  [%8hd, %8hd, %8hd, %8hd, %8hd, %8hd, %8hd, %8hd]\n",
		rs.mu16[0], rs.mu16[1], rs.mu16[2], rs.mu16[3], rs.mu16[4], rs.mu16[5], rs.mu16[6], rs.mu16[7]);
	puts("");
}

int main(void) {
	addI16C();
	addU16C();
	return 0;
}