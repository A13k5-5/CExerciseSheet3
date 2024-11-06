#include "graphics.h"
#include "background.h"
#include "main.h"
#include <stdio.h>

// This function converts real (x,y) coords into grid coords
int coordsToGrid(map *map, int x)
{
    return (x - map->canvas.offset) / map->canvas.squareSize;
}

int gridToCoords(map *map, int x)
{
    return x * map->canvas.squareSize + map->canvas.offset;
}

void drawGridSquares(map *map, int x, int y)
{
    drawRect(gridToCoords(map, x), gridToCoords(map, y), map->canvas.squareSize, map->canvas.squareSize);
    colour col = map->map[y][x] == 'w' ? red : map->map[y][x] == 'm' ? gray
                                                                     : black;
    setColour(col);
    if (map->map[y][x] != 'o')
    {
        fillRect(gridToCoords(map, x), gridToCoords(map, y), map->canvas.squareSize, map->canvas.squareSize);
    }
    setColour(black);
    drawRect(gridToCoords(map, x), gridToCoords(map, y), map->canvas.squareSize, map->canvas.squareSize);
}

void drawBackground(map *map)
{
    setWindowSize(map->canvas.width, map->canvas.height);
    background();
    for (int y = 0; y < map->height; y++)
    {
        for (int x = 0; x < map->width; x++)
        {
            drawGridSquares(map, x, y);
        }
    }
}