using System;
using System.Runtime.InteropServices;

namespace additiion
{
    class additiion
    {
        [DllImport("D:\\Study\\C\\dll\\addition\\C\\test.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern int add_numbers(int a, int b);

        static void Main(string[] args)
        {
            int result = add_numbers(5, 7);
            Console.WriteLine("C# Result: " + result);
        }
    }
}
