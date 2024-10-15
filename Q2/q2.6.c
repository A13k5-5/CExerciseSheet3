// Written by api on 08/10/2024
// This program displays an arrow of *

#include <stdio.h>
#include <stdlib.h>

void draw_arrow(int size)
{
    for (int i = 0; i < 2 * size + 1; i++)
    {
        int gap = size - abs(i - size);

        for (int j = 0; j < gap; j++)
        {
            printf(" ");
        }

        for (int j = 0; j < size; j++)
        {
            printf("*");
        }
        printf("\n");
    }
}

int main(void)
{
    draw_arrow(5);
    return 0;
}