#pragma once
#include "main.h"
typedef struct point
{
    int x;
    int y;
} point;

int coordsToGrid(map map, int x);
int gridToCoords(map map, int x);
void drawBackground(map map);