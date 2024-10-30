// This draws the background

#include "graphics.h"
#include "background.h"
#include <stdio.h>

// This function converts real (x,y) coords into grid coords
int coordsToGrid(canvas canvas, int x)
{
    return x / canvas.squareSize;
}

int gridToCoords(canvas canvas, int x)
{
    return x * canvas.squareSize;
}

void drawGrid(canvas canvas)
{
    background();
    for (int y = 1; y < coordsToGrid(canvas, canvas.height); y += 1)
    {
        for (int x = 1; x < coordsToGrid(canvas, canvas.width) - 1; x += 1)
        {
            (y == 1 || y == coordsToGrid(canvas, canvas.height) - 1 || x == 1 || x == coordsToGrid(canvas, canvas.width) - 2) ? setColour(red) : setColour(black);
            drawRect(gridToCoords(canvas, x), gridToCoords(canvas, y), canvas.squareSize, canvas.squareSize);
        }
    }
}

int main(void)
{
    canvas canvas = {500, 500, 50};
    setWindowSize(canvas.width, canvas.height);
    drawGrid(canvas);
    return 0;
}
