// Written by api on 27/10/2024
// This code is from COMP0002 presentation on pointers

#include <stdio.h>

void printArr(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void f()
{
    int i1, i2;
    int *p1, *p2;
    i1 = 5;
    p1 = &i1;
    i2 = *p1 / 2 + 10;
    p2 = p1;
    printf("i1 = %d, i2 = %d, *p1 = %d, *p2 = %d\n", i1, i2, *p1, *p2);
}

void pointerArithmetic()
{
    int myArray[] = {10, 22, 6, 43, 19, 27};
    int *p = myArray;
    printArr(myArray, sizeof(myArray) / sizeof(myArray[0]));
    *p = 20;
    printArr(myArray, sizeof(myArray) / sizeof(myArray[0]));
    *(p + 1) = 30;
    printArr(myArray, sizeof(myArray) / sizeof(myArray[0]));
}

int main(void)
{
    f();
    pointerArithmetic();
    return 0;
}