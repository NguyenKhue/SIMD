#include <iostream>
#include <arm/sve.h>
#include <arm/neon.h>
#include <x86/sse3.h>
#include <x86/avx.h>
#define SIMDE_ENABLE_NATIVE_ALIASES

// Function declarations
void displayResult(const char *operation, const float *SIMDdata, int size);

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {

    float data1[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    float data2[8] = {101, 102, 103, 104, 105, 106, 107, 108};
    simde__m256 vector1 = simde_mm256_load_ps(data1);
    simde__m256 vector2 = simde_mm256_load_ps(data2);
    auto result = simde_mm256_add_ps(vector1, vector2);

    displayResult("Addition Result", reinterpret_cast<float *>(&result), 8);

    simde_int32x4_t a[] = {1 , 2 , 3, 4};
    simde_int32x4_t b[] = {1 , 2, 3, 4};;

    auto result2 = simde_vaddq_s32(*a, *b);

    std::cout << "Result 2: " << result2[1] <<"\n";

    return 0;
}

void displayResult(const char *operation, const float *SIMDdata, int size) {
    std::cout << operation << ": ";
    for (int lane = 0; lane < size; ++lane) {
        std::cout << SIMDdata[lane] << ", ";
    }
    std::cout << std::endl;
}
