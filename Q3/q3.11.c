// Written by api on 27/10/2024
// This program draws a plus pattern over a canvas

// To compile: gcc q3.11.c graphics.c -o plusPattern
// To run: ./plusPattern | java -jar drawapp-3.0.jar

#include <stdio.h>
#include <stdbool.h>
#include "graphics.h"

void drawPattern(int gridSize, int CanvasHeight, int CanvasWidth)
{
    bool isBlue = false;
    for (int i = 0; i < CanvasWidth; i += gridSize)
    {
        setColour(isBlue ? blue : yellow);
        isBlue = !isBlue;
        fillRect(i, 0, i + gridSize, gridSize);
    }
}

int main(void)
{
    int height = 500;
    int width = 500;
    setWindowSize(height, width);
    drawPattern(10, height, width);
    return 0;
}