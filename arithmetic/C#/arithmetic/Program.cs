using System;
using System.Runtime.InteropServices;

namespace arithmetic
{
    class arithmetic
    {
        [DllImport("D:\\Study\\C\\dll\\arithmetic\\C\\test.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern int add_numbers(int a, int b);
        [DllImport("D:\\Study\\C\\dll\\arithmetic\\C\\test.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern int subtract_numbers(int a, int b);
        [DllImport("D:\\Study\\C\\dll\\arithmetic\\C\\test.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern int multiply_numbers(int a, int b);
        [DllImport("D:\\Study\\C\\dll\\arithmetic\\C\\test.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern int divide_numbers(int a, int b);

        static void Main(string[] args)
        {
            int result = add_numbers(5, 7);
            Console.WriteLine("Addition Result: " + result);
            result = subtract_numbers(5, 7);
            Console.WriteLine("Subtraction Result: " + result);
            result = multiply_numbers(5, 7);
            Console.WriteLine("Multiplication Result: " + result);
            result = divide_numbers(10, 2);
            Console.WriteLine("Division Result: " + result);

            Console.ReadKey();
        }
    }
}
