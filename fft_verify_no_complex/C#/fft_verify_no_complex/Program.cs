using System;
using System.Numerics;
using System.Runtime.InteropServices;

namespace fft_verify_no_complex
{
    class fft_verify_no_complex
    {
        const int N = 16;

        [DllImport("D:\\Study\\C\\dll\\fft_verify_no_complex\\C\\test.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern void fft_calculate(float[] input_real, float[] input_imag, int size);
        [DllImport("D:\\Study\\C\\dll\\fft_verify_no_complex\\C\\test.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern int add_numbers(int a, int b);

        static void Main(string[] args)
        {
            Console.WriteLine($"Result: {add_numbers(5, 7)}");

            float[] input_real = new float[N] { 10, 21, 45, 52, 51, 68, 50, 31, 11, 29, 16, 16, 5, 1, 0, 0 };
            float[] input_imag = new float[N] { 11, 48, 109, 154, 125, 113, 66, 42, 21, 33, 68, 8, 7, 1, 1, 0 };

            // DLL 함수 호출
            fft_calculate(input_real, input_imag, N);

            // 결과 출력
            for (int i = 0; i < N; i++)
            {
                Console.WriteLine($"FFT[{i}] = {input_real[i]} + {input_imag[i]}i");
            }

            Console.ReadKey();
        }
    }
}
