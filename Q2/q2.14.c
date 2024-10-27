// Written by api on 17/10/2024
// This program draws a rectangle of any character and dimensions

#include <stdio.h>

void drawRectangle(int height, int width, char c)
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            printf("%c", c);
        }
        printf("\n");
    }
}

int main(void)
{
    drawRectangle(5, 6, '&');
    return 0;
}
