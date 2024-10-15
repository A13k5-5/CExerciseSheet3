// Written by api on 08/10/2024
// This program displays a triangle of *

#include <stdio.h>

void draw_triangle(int size)
{
    for (int i = size; i > 0; i--)
    {
        for (int j = 0; j < size - i; j++)
        {
            printf(" ");
        }

        for (int j = 0; j < i; j++)
        {
            printf("*");
        }
        printf("\n");
    }
}

int main(void)
{
    draw_triangle(6);
    return 0;
}