// Written by api on 03/10/2024
// This programs draws a sine wave

#include <stdio.h>
#include "graphics.h"
#include <math.h>

int main(void)
{
    const float PI = 3.1415926536;
    int PERIOD = 2 * PI;
    int x = 0;
    float y;

    for (int i = 0; i < 500; i++)
    {

        y = (int)(50 * sin(-x / 360.0 * 2 * PI)) + 150;
        x += 1;

        // Draw a point
        drawLine(x, y, x, y);
    }
    return 0;
}