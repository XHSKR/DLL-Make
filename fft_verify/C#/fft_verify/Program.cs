using System;
using System.Numerics;
using System.Runtime.InteropServices;

namespace fft_verify
{
    class fft_verify
    {
        const int N = 16;
        const double PI = 3.14159265358979323846;

        [DllImport("D:\\Study\\C\\dll\\fft_verify\\C\\test.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern void fft_calculate(Complex[] input, int size);

        static void Main(string[] args)
        {
            Complex[] input = new Complex[N]
            {
                new Complex(10, 11), new Complex(21, 48), new Complex(45, 109), new Complex(52, 154),
                new Complex(51, 125), new Complex(68, 113), new Complex(50, 66), new Complex(31, 42),
                new Complex(11, 21), new Complex(29, 33), new Complex(16, 68), new Complex(16, 8),
                new Complex(5, 7), new Complex(1, 1), new Complex(0, 1), new Complex(0, 0)
            };

            // DLL 함수 호출
            fft_calculate(input, N);

            // 결과 출력
            for (int i = 0; i < N; i++)
            {
                Console.WriteLine($"FFT[{i}] = {input[i].Real} + {input[i].Imaginary}i");
            }

            Console.ReadKey();
        }
    }
}
