// add_dll.c
#include <stdio.h>

extern __declspec(dllexport) int add_numbers(int a, int b)
{
    return a + b;
}

extern __declspec(dllexport) int subtract_numbers(int a, int b)
{
    return a - b;
}

extern __declspec(dllexport) int multiply_numbers(int a, int b)
{
    return a * b;
}

extern __declspec(dllexport) int divide_numbers(int a, int b)
{
    return a / b;
}