// Written by api on 04/10/2024 - 14/10/2024
// This program draws the Koch star / Koch snowflake

#include "graphics.h"
#include <stdio.h>
#include <math.h>

void drawKochStar(int x1, int y1, int x5, int y5, int depth)
{
    if (depth == 0)
    {
        drawLine(x1, y1, x5, y5);
    }
    else
    {
        int dx = x5 - x1;
        int dy = y5 - y1;

        int x2 = x1 + dx / 3;
        int y2 = y1 + dy / 3;

        int x3 = (int)(0.5 * (x1 + x5) - sqrt(3) * dy / 6);
        int y3 = (int)(0.5 * (y1 + y5) + sqrt(3) * dx / 6);

        int x4 = x2 + dx / 3;
        int y4 = y2 + dy / 3;

        drawKochStar(x1, y1, x2, y2, depth - 1);
        drawKochStar(x2, y2, x3, y3, depth - 1);
        drawKochStar(x3, y3, x4, y4, depth - 1);
        drawKochStar(x4, y4, x5, y5, depth - 1);
    }
}

int main(void)
{
    int depth = 3;
    drawKochStar(100, 100, 200, 100, depth);
    drawKochStar(200, 100, 150, 100 - (int)sqrt(100 * 100 - 50 * 50), depth);
    drawKochStar(150, 100 - (int)sqrt(100 * 100 - 50 * 50), 100, 100, depth);
    return 0;
}