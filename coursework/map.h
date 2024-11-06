#pragma once
void printMap(char **map, int width, int height);
void generateWall(char **map, int width, int height);
char **generateEmptyMap(int width, int height);
char **generateMap(int width, int height);
char **copyMap(map *map);