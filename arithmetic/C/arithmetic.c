// use_dll.c
#include <stdio.h>
#include <windows.h>

typedef int(__cdecl *AddNumbersFunction)(int, int);

int main()
{
    HINSTANCE hDll = LoadLibrary("add_dll.dll");
    AddNumbersFunction addFunc = (AddNumbersFunction)GetProcAddress(hDll, "add_numbers");

    int result = addFunc(5, 7);
    printf("C Result: %d\n", result);

    FreeLibrary(hDll);
    return 0;
}
