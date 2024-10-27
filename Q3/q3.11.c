// Written by api on 27/10/2024
// This program draws a plus pattern over a canvas

// To compile: gcc q3.11.c graphics.c -o plusPattern
// To run: ./plusPattern | java -jar drawapp-3.0.jar

#include <stdio.h>
#include "graphics.h"

void drawPattern(int gridSize, int CanvasHeight, int CanvasWidth)
{
    setColour(blue);
    fillRect(50, 50, 50, 50);
    drawLine(0, 0, 500, 500);
}

int main(void)
{
    int height = 500;
    int width = 500;
    setWindowSize(height, width);
    drawPattern(50, height, width);
    return 0;
}