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
    int *obsX = generateRandomNumbers(howMany, 1, width - 2);
    int *obsY = generateRandomNumbers(howMany, 1, height - 2);
    int *obsLengths = generateRandomNumbers(howMany, 1, 4);
    for (int i = 0; i < howMany; i++)
    {
        for (int j = 0; j < obsLengths[i]; j++)
        {
            if (obsX[i] + j >= width - 2)
                break;
            map[obsY[i]][obsX[i] + j] = 'b';
        }
    }
}

void generateMarkers(int howMany, char **map, int width, int height)
{
    for (int i = 0; i < howMany; i++)
    {
        point p = generateRandomPoint(width, height);
        // if (map[p.y][p.x] != 'o')
        // {
        //     i--;
        // }
        // else
        {
            map[p.y][p.x] = 'm';
        }
    }
}

char **generateMap(int width, int height)
{
    char **map = generateEmptyMap(width, height);
    generateWall(map, width, height);
    generateObstacles(map, width, height, (height + width) / 2);
    generateMarkers((height + width) / 4, map, width, height);
    map[1][2] = 'h';
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