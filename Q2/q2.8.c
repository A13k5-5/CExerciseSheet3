// Written by api on 14/10/2024
// This program draws a chessboard of '#' and '*'

#include <stdio.h>
#include <stdbool.h>

void drawChessboard(int x, int y)
{
    bool hash = false;

    for (int i = 0; i < y; i++)
    {
        for (int j = 0; j < x; j++)
        {
            char output = hash ? '#' : '*';
            printf("%c", output);
            hash = !hash;
        }
        hash = !hash;
        printf("\n");
    }
}

int main(void)
{
    drawChessboard(8, 8);
    return 0;
}