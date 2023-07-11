#include <stdio.h>
#include <sal.h>
#include "packed.h"

static void __forceinline AddI16_AVX(const xmm_t* _In_ arr_packed_0, const xmm_t* _In_ arr_packed_1,
    xmm_t* _Out_ sat_sum, xmm_t* _Out_ flpar_sum) {

    __m128i xmm_arr0 = _mm_load_si128((const __m128i*) arr_packed_0);
    __m128i xmm_arr1 = _mm_load_si128((const __m128i*) arr_packed_1);

    __m128i xmm_fliparound_sum = _mm_add_epi16(xmm_arr0, xmm_arr1);
    __m128i xmm_saturated_sum = _mm_adds_epi16(xmm_arr0, xmm_arr1);

    return;
}