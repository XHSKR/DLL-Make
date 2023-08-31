#include <stdio.h>
#include <math.h>

#define N 16 // 16 //32 //64
#define PI 3.14159265358979323846

void fft_calculate(float *input_real, float *input_imag, int size)
{
    // Bit-reverse permutation
    for (int i = 0; i < size; i++)
    {
        int j = 0;
        for (int k = 0; k < log2(size); k++)
        {
            j = (j << 1) | ((i >> k) & 1);
        }
        if (j > i)
        {
            float temp_real = input_real[i];
            float temp_imag = input_imag[i];
            input_real[i] = input_real[j];
            input_imag[i] = input_imag[j];
            input_real[j] = temp_real;
            input_imag[j] = temp_imag;
        }
    }

    // Perform iterative FFT
    for (int step = 1; step < size; step *= 2)
    {
        for (int offset = 0; offset < size; offset += 2 * step)
        {
            for (int n = 0; n < step; n++)
            {
                int i = offset + n;
                int j = offset + n + step;
                float w_real = cos(-2 * PI * n / (2 * step));
                float w_imag = sin(-2 * PI * n / (2 * step));
                float real_diff = input_real[i] - input_real[j];
                float imag_diff = input_imag[i] - input_imag[j];
                input_real[j] = input_real[i] - (real_diff * w_real - imag_diff * w_imag);
                input_imag[j] = input_imag[i] - (real_diff * w_imag + imag_diff * w_real);
                input_real[i] = input_real[i] + (real_diff * w_real - imag_diff * w_imag);
                input_imag[i] = input_imag[i] + (real_diff * w_imag + imag_diff * w_real);
            }
        }
    }
}

int main()
{
    float input_real[N] = {10, 21, 45, 52, 51, 68, 50, 31, 11, 29, 16, 16, 5, 1, 0, 0};
    float input_imag[N] = {11, 48, 109, 154, 125, 113, 66, 42, 21, 33, 68, 8, 7, 1, 1, 0};

    // FFT 계산
    fft_calculate(input_real, input_imag, N);

    // FFT 결과 출력
    for (int i = 0; i < N; i++)
    {
        printf("FFT[%d] = %f + %fi\n", i, input_real[i], input_imag[i]);
    }

    return 0;
}
