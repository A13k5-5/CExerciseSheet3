// Written by api on 15/10/2024
// This program draws two triangles adjacent to each other

#include <stdio.h>
#include <stdlib.h>

void drawTriangle(int height)
{
    char output;
    // Rows
    for (int i = 0; i < height + 1; i++)
    {
        // Left triangle
        for (int j = 0; j < i; j++)
        {
            output = (j == 0 || j == i - 1 || i == height) ? '#' : ' ';
            printf("%c", output);
        }
        // Right triangle
        for (int j = height - i - 1; j > -1; j--)
        {
            output = (i == 0 || j == 0 || j == height - i - 1) ? '*' : ' ';
            printf("%c", output);
        }
        printf("\n");
    }
}

int main(void)
{
    drawTriangle(8);
    return 0;
}