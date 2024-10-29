// This draws the background

#include "graphics.h"
#include "background.h"

void drawGrid(canvas canvas, int squareSize)
{
    for (int y = squareSize; y < canvas.height - squareSize; y += squareSize)
    {
        for (int x = squareSize; x < canvas.width - squareSize; x += squareSize)
        {
            drawRect(x, y, squareSize, squareSize);
        }
    }
}

void drawBackground(canvas canvas)
{
    int squareSize = 50;
    drawGrid(canvas, squareSize);
}

int main(void)
{
    canvas canvas = {500, 500};
    setWindowSize(canvas.width, canvas.height);
    drawBackground(canvas);
    return 0;
}
