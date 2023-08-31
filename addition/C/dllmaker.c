// add_dll.c
#include <stdio.h>

extern __declspec(dllexport) int add_numbers(int a, int b)
{
    return a + b;
}