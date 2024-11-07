#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "main.h"
#include "random.h"

void printMap(char **map, int width, int height)
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            printf("%c ", map[i][j]);
        }
        printf("\n");
    }
}

void printArr(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%i ", arr[i]);
    }
    printf("\n");
}

char **generateEmptyMap(int width, int height)
{
    char **map = (char **)malloc((height) * sizeof(char *));
    for (int i = 0; i < height; i++)
    {
        map[i] = (char *)malloc(width * sizeof(char));
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            map[i][j] = 'o';
        }
    }
    return map;
}

// generates wall around edges
void generateWall(char **map, int width, int height)
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (i == 0 || i == height - 1 || j == 0 || j == width - 1)
            {
                map[i][j] = 'w';
            }
        }
    }
}

void generateObstacles(char **map, int width, int height, int howMany)
{
    point *points = generateRandomPoints(width, height, howMany);
    int *obsLengths = generateRandomNumbers(howMany, 1, 4);
    bool horizontal = false;
    for (int i = 0; i < howMany; i++)
    {
        horizontal = randomNumber(0, 1);
        for (int j = 0; j < obsLengths[i]; j++)
        {
            if ((points[i].x + j >= width - 2 && horizontal) || (points[i].y + j >= height - 2 && !horizontal))
                break;
            map[points[i].y + (horizontal ? 0 : j)][points[i].x + (horizontal ? j : 0)] = 'b';
        }
    }
}

void generateMarkers(int howMany, char **map, int width, int height)
{
    for (int i = 0; i < howMany; i++)
    {
        point p = randomEmptyPointOnMap(map, width, height);
        map[p.y][p.x] = 'm';
    }
}

void setHome(char **map, int width, int height)
{
    point p = randomEmptyPointOnMap(map, width, height);
    map[p.y][p.x] = 'h';
}

char **generateMap(int width, int height)
{
    char **map = generateEmptyMap(width, height);
    generateWall(map, width, height);
    setHome(map, width, height);
    generateMarkers((height + width) / 4, map, width, height);
    generateObstacles(map, width, height, (height + width) / 4);
    return map;
}

char **copyMap(map *map)
{
    char **mapCopy = generateEmptyMap(map->width, map->height);
    for (int i = 0; i < map->height; i++)
    {
        for (int j = 0; j < map->width; j++)
        {
            mapCopy[i][j] = map->map[i][j];
        }
    }
    return mapCopy;
}