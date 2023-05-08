#include <stdio.h>
#include <immintrin.h>
#include <stdalign.h>

typedef float _ymm_t[6];
#define ymm_t alignas(32) _ymm_t

int main(void) {

    alignas(32) float array_1[6] = { 0.0f, 0.1f, 0.2f, 0.3f, 0.4f, 0.5f };
    alignas(32) float array_2[6] = { 0.6f, 0.5f, 0.4f, 0.3f, 0.2f, 0.1f };
    alignas(32) float sums[6] = { 0.0f };

    ymm_t array_3 = { 0.0f, 0.1f, 0.2f, 0.3f, 0.4f, 0.5f };
    ymm_t array_4 = { 0.0f, 0.1f, 0.2f, 0.3f, 0.4f, 0.5f };
    ymm_t sums_ = { 0.0f };

    __m256 ymm0_f32 = _mm256_load_ps(array_1);
    __m256 ymm1_f32 = _mm256_load_ps(array_2);

    __m256 ymm_res = _mm256_add_ps(ymm0_f32, ymm1_f32);
    _mm256_store_ps(sums, ymm_res);

    __m256 ymm3_f32 = _mm256_load_ps(array_3);
    __m256 ymm4_f32 = _mm256_load_ps(array_4);

    __m256 ymm_res_ = _mm256_add_ps(ymm3_f32, ymm4_f32);
    _mm256_store_ps(sums_, ymm_res_);

    printf_s("Sums is %.2f %.2f %.2f %.2f %.2f %.2f\n", sums[0], sums[1], sums[2], sums[3], sums[4], sums[5]);
    printf_s("Sums is %.2f %.2f %.2f %.2f %.2f %.2f\n", sums_[0], sums_[1], sums_[2], sums_[3], sums_[4], sums_[5]);
    return 0;
}