#pragma once
void printMap(char **map, int width, int height);
char **generateMap(int width, int height);
char **copyMap(char **map, int width, int height);
void resetVisited(char **map, int height, int width);
point *neighbourPoints(point p);