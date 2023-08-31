// DLL Maker
#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

extern __declspec(dllexport) int add_numbers(int a, int b)
{
    return a + b;
}

extern __declspec(dllexport) void fft_calculate(float *input_real, float *input_imag, int size)
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