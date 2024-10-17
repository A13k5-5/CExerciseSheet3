// Written by api on 16/10/2024
// This program draws the three trigonometric functions on a coordinate system

#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include "graphics.h"

void drawSine(int xMin, int xMax, int domain)
{
    for (int i = xMin; i < xMax; i++)
    {
        int y = -(int)(sin(i * 2.0 * M_PI / domain) * domain / (2 * M_PI)) + 400;
        drawLine(i, y, i, y);
    }
}

void drawCosine(int xMin, int xMax, int domain)
{
    for (int i = xMin; i < xMax; i++)
    {
        int y = -(int)(cos(i * 2.0 * M_PI / domain) * domain / (2 * M_PI)) + 400;
        drawLine(i, y, i, y);
    }
}

void drawTan(int xMin, int xMax, int domain)
{
    for (int i = xMin; i < xMax; i++)
    {
        int y = -(int)(tan(i * 2.0 * M_PI / domain) * domain / (2 * M_PI)) + 400;
        drawLine(i, y, i, y);
    }
}

void drawCoordAxis()
{
    // x-axis
    drawLine(0, 400, 800, 400);
    // y-axis
    drawLine(400, 0, 400, 800);
}

int main(void)
{
    setWindowSize(800, 800);
    drawCoordAxis();
    drawSine(0, 800, 800);
    drawCosine(0, 800, 800);
    drawTan(0, 800, 800);
    return 0;
}