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
    background();
    for (int y = 0; y < map.height; y++)
    {
        for (int x = 0; x < map.width; x++)
        {
            colour col = map.map[y][x] == 'w' ? red : map.map[y][x] == 'm' ? gray
                                                                           : black;
            setColour(col);
            if (map.map[y][x] == 'o')
            {
                drawRect(gridToCoords(map, x + 1), gridToCoords(map, y + 1), map.canvas.squareSize, map.canvas.squareSize);
            }
            else
            {
                fillRect(gridToCoords(map, x + 1), gridToCoords(map, y + 1), map.canvas.squareSize, map.canvas.squareSize);
            }
        }
    }
}