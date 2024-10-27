// Written by api on 27/10/2024
// This program draws a plus pattern over a canvas

// To compile: gcc q3.11.c graphics.c -o plusPattern
// To run: ./plusPattern | java -jar drawapp-3.0.jar

#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include "graphics.h"

void drawPattern(int gridSize, int CanvasHeight, int CanvasWidth)
{
    int colours[] = {3, 1, 1};
    int curColourId = 1;
    int colourChange = 2;
    bool isBlue = true;
    for (int i = 0; i < CanvasHeight / gridSize; i++)
    {
        for (int j = 0; j < CanvasWidth / gridSize; j++)
        {
            setColour(isBlue ? blue : yellow);
            int x = j * gridSize - 3 * i * gridSize < 0 ? CanvasWidth + (j * gridSize - 3 * i * gridSize) % CanvasWidth : j * gridSize - 3 * i * gridSize;
            fillRect(x, i * gridSize, gridSize, gridSize);
            if (j == colourChange)
            {
                isBlue = !isBlue;
                colourChange = (colourChange + colours[curColourId]) % (CanvasWidth / gridSize);
                curColourId = (curColourId + 1) % 3;
            }
        }
    }
}

int main(void)
{
    int height = 500;
    int width = 500;
    setWindowSize(height, width);
    drawPattern(25, height, width);
    return 0;
}