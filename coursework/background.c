#include "graphics.h"
#include "background.h"
#include "main.h"
#include "map.h"
#include <stdio.h>

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
    colour col = map->map[y][x] == WALL ? red : map->map[y][x] == MARKER ? gray
                                            : map->map[y][x] == HOME     ? blue
                                                                         : black;
    setColour(col);
    if (map->map[y][x] != EMPTY)
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