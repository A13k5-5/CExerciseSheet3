// Written by api on 16/10/2024
// This program draws the three trigonometric functions on a coordinate system

// To compile:gcc q2.12.c graphics.c -lm -o drawTrigFunctions
// To run: ./drawTrigFunctions | java -jar drawapp-3.0.jar

#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include "graphics.h"

void drawTrigFunction(double (*trigfunction)(double), int xMin, int xMax, int domain)
{
    for (int i = xMin; i < xMax; i++)
    {
        int y = -(int)(trigfunction(i * 2.0 * M_PI / domain) * domain / (2 * M_PI)) + 400;
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
    drawTrigFunction(sin, 0, 800, 800);
    drawTrigFunction(cos, 0, 800, 800);
    drawTrigFunction(tan, 0, 800, 800);
    return 0;
}