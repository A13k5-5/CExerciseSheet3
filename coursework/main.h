#pragma once
typedef struct canvas
{
    int width;
    int height;
    int squareSize;
} canvas;
typedef struct map
{
    int width;
    int height;
    canvas canvas;
    char **map;
} map;

void printMap(char **map, int width, int height);
