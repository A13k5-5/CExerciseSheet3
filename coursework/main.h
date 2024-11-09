#pragma once
typedef struct
{
    int width;
    int height;
    int squareSize;
    int offset;
} canvas;
typedef struct
{
    int x;
    int y;
} point;
typedef struct
{
    int width;
    int height;
    canvas canvas;
    char **map;
} map;
