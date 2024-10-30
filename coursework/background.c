// This draws the background

#include "graphics.h"
#include "background.h"
#include "main.h"
#include <stdio.h>

// This function converts real (x,y) coords into grid coords
int coordsToGrid(map map, int x)
{
    return x / map.canvas.squareSize;
}

int gridToCoords(map map, int x)
{
    return x * map.canvas.squareSize;
}

void drawBackground(map map)
{
    setWindowSize(map.canvas.width, map.canvas.height);
    for (int y = 0; y < map.height; y++)
    {
        for (int x = 0; x < map.width; x++)
        {
            map.map[y][x] == 'w' ? setColour(red) : setColour(black);
            drawRect(gridToCoords(map, x), gridToCoords(map, y), map.canvas.squareSize, map.canvas.squareSize);
        }
    }
}