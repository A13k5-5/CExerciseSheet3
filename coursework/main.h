#pragma once
typedef struct canvas
{
    int width;
    int height;
    int squareSize;
    int offset;
} canvas;
typedef struct point
{
    int x;
    int y;
} point;
typedef struct map
{
    int width;
    int height;
    canvas canvas;
    char **map;
} map;

void printMap(char **map, int width, int height);
