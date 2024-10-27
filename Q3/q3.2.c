// Written by api on 21/10/2024
// This is a implementation of a to the power function

#include <stdio.h>

int powRecur(int num, int pow)
{
    if (pow == 0)
    {
        return 1;
    }
    return num * powRecur(num, pow - 1);
}

int powFor(int num, int pow)
{
    int acc = 1;
    for (int i = 0; i < pow; i++)
    {
        acc *= num;
    }
    return acc;
}

void printArr(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%i ", arr[i]);
    }
    printf("\n");
}

// int main(void)
// {
//     printf("%i\n", powRecur(5, 1));
//     printf("%i\n", powFor(5, 3));
//     return 0;
// }