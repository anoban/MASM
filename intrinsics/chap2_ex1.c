#include <stdio.h>
#include <sal.h>
#include "packed.h"

static void inline AddI16_AVX(_In_ const xmm_t* arr_packed_0, _In_ const xmm_t* arr_packed_1,
    _Out_ xmm_t* sat_sums, _Out_ xmm_t* flpar_sums) {

    __m128i xmm_arr0 = _mm_load_si128((const __m128i*) arr_packed_0);
    __m128i xmm_arr1 = _mm_load_si128((const __m128i*) arr_packed_1);

    __m128i xmm_fliparound_sums = _mm_add_epi16(xmm_arr0, xmm_arr1);
    __m128i xmm_saturated_sums = _mm_adds_epi16(xmm_arr0, xmm_arr1);

    _mm_store_si128((__m128i*) flpar_sums, xmm_fliparound_sums);
    _mm_store_si128((__m128i*) sat_sums, xmm_saturated_sums);

    return;
}


static void inline AddU16_AVX(_In_ const xmm_t* arr_packed_0, _In_ const xmm_t* arr_packed_1,
    _Out_ xmm_t* sat_sums, _Out_ xmm_t* flpar_sums) {

    __m128i xmm_arr0 = _mm_load_si128((const __m128i*) arr_packed_0);
    __m128i xmm_arr1 = _mm_load_si128((const __m128i*) arr_packed_1);

    // NOTE:
    // There's no packed unsigned equivalent for _mm_add_epi16.
    __m128i xmm_fliparound_sums = _mm_add_epi16(xmm_arr0, xmm_arr1);
    __m128i xmm_saturated_sums = _mm_adds_epu16(xmm_arr0, xmm_arr1);

    _mm_store_si128((__m128i*) flpar_sums, xmm_fliparound_sums);
    _mm_store_si128((__m128i*) sat_sums, xmm_saturated_sums);

    return;
}