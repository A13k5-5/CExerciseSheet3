// Written by api on 14/10/2024
// This program draws a bow

#include <stdio.h>
#include <stdlib.h>

void drawBow(int width)
{
    for (int i = 0; i < 2 * width + 1; i++)
    {
        printf("*");
        int gap = width - abs(i - width);
        for (int j = 0; j < gap; j++)
        {
            char output = j == gap - 1 ? '*' : ' ';
            printf("%c", output);
        }
        printf("\n");
    }
}

int main(void)
{
    drawBow(5);
    return 0;
}
