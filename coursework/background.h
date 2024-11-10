#pragma once
#include "main.h"
#include "graphics.h"

#define WALL_COLOUR red
#define MARKER_COLOUR gray
#define OBSTACLE_COLOUR black
#define HOME_COLOUR blue
#define EMPTY_COLOUR black

int coordsToGrid(map *map, int x);
int gridToCoords(map *map, int x);
void drawBackground(map *map);