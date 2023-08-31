// fft_dll.c
#include <stdio.h>
#include <complex.h>
#include <math.h>

#define PI 3.14159265358979323846

extern __declspec(dllexport) void fft_calculate(float __complex__ *input, int size)
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
            float __complex__ temp = input[i];
            input[i] = input[j];
            input[j] = temp;
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
                float __complex__ w = cexp(-2 * PI * I * n / (2 * step));
                float __complex__ wn = input[j] * w;
                input[j] = input[i] - wn;
                input[i] = input[i] + wn;
            }
        }
    }
}