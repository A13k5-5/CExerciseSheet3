// Written by api on 17/10/2024
// This program draws a spiral

#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>
#include "graphics.h"

void drawSpiral(int x, int y)
{
    int centre[2] = {x, y};
    int Sx, Sy;
    for (int i = 0; i < 10000; i++)
    {
        Sx = centre[0] + i / 50.0 * cos(i * 2.0 * M_PI / 500);
        Sy = centre[1] + i / 50.0 * sin(i * 2.0 * M_PI / 500);

        drawLine(Sx, Sy, Sx, Sy);
    }
}

int main(void)
{
    setWindowSize(500, 500);
    drawSpiral(250, 250);
    return 0;
}