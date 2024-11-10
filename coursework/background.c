#include <stdio.h>
#include "background.h"
#include "main.h"
#include "graphics.h"
#include "map.h"

int coordsToGrid(map *map, int x)
{
    return (x - map->canvas.offset) / map->canvas.squareSize;
}

int gridToCoords(map *map, int x)
{
    return x * map->canvas.squareSize + map->canvas.offset;
}

colour squareColour(char square)
{
    switch (square)
    {
    case WALL:
        return WALL_COLOUR;
    case OBSTACLE:
        return OBSTACLE_COLOUR;
    case HOME:
        return HOME_COLOUR;
    case MARKER:
        return MARKER_COLOUR;
    default:
        return EMPTY_COLOUR;
    }
}

void drawGridSquares(map *map, int x, int y)
{
    drawRect(gridToCoords(map, x), gridToCoords(map, y), map->canvas.squareSize, map->canvas.squareSize);
    colour col = squareColour(map->map[y][x]);
    setColour(col);
    if (map->map[y][x] != EMPTY)
    {
        fillRect(gridToCoords(map, x), gridToCoords(map, y), map->canvas.squareSize, map->canvas.squareSize);
    }
    setColour(EMPTY_COLOUR);
    drawRect(gridToCoords(map, x), gridToCoords(map, y), map->canvas.squareSize, map->canvas.squareSize);
}

void drawBackground(map *map)
{
    setWindowSize(map->canvas.width, map->canvas.height);
    background();
    clear();
    for (int y = 0; y < map->height; y++)
    {
        for (int x = 0; x < map->width; x++)
        {
            drawGridSquares(map, x, y);
        }
    }
}