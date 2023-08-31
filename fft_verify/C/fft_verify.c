#include <stdio.h>
#include <complex.h>
#include <math.h>

#define N 16 // 16 //32 //64
#define PI 3.14159265358979323846

void fft_calculate(float __complex__ *input, int size)
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

int main()
{
    float __complex__ input[N] = {(10) + (11 * I), (21) + (48 * I), (45) + (109 * I), (52) + (154 * I), (51) + (125 * I), (68) + (113 * I), (50) + (66 * I), (31) + (42 * I), (11) + (21 * I), (29) + (33 * I), (16) + (68 * I), (16) + (8 * I), (5) + (7 * I), (1) + (1 * I), (0) + (1 * I), (0) + (0 * I)};

    // FFT 계산
    fft_calculate(input, N);

    // FFT 결과 출력
    for (int i = 0; i < N; i++)
    {
        printf("FFT[%d] = %f + %fi\n", i, creal(input[i]), cimag(input[i]));
    }

    return 0;
}
