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

point *neighbourPoints(point p)
{
    point *neighbouringPoints = (point *)malloc(4 * sizeof(point));
    neighbouringPoints[0] = (point){p.x, p.y - 1}; // North
    neighbouringPoints[1] = (point){p.x, p.y + 1}; // South
    neighbouringPoints[2] = (point){p.x + 1, p.y}; // West
    neighbouringPoints[3] = (point){p.x - 1, p.y}; // East
    return neighbouringPoints;
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

void generateIrregularArena(char **map, int width, int height, point curPos, int depth)
{
    if (curPos.x < 0 || curPos.x >= width - 1 || curPos.y < 0 || curPos.y >= height - 1)
    {
        return;
    }
    map[curPos.y][curPos.x] = 'w';

    point *directions = neighbourPoints(curPos);

    for (int i = 0; i < 4; i++)
    {
        if ((randomNumber(0, 2) == 0 && depth < 8) || !depth)
        {
            generateIrregularArena(map, width, height, directions[i], depth + 1);
        }
    }
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
    point start = {1, 1};
    generateIrregularArena(map, width, height, start, 0);
    point start2 = {width - 2, 1};
    generateIrregularArena(map, width, height, start2, 0);
}

void resetVisited(char **map, int height, int width)
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (map[i][j] == 'v')
            {
                map[i][j] = 'o';
            }
        }
    }
}

void generateObstacles(char **map, int width, int height, int howMany)
{
    point *points = generateRandomPoints(width, height, howMany);
    bool horizontal = false;
    for (int i = 0; i < howMany; i++)
    {
        point p = randomEmptyPointOnMap(map, 'o', width, height);
        int obsLength = randomNumber(1, 4);
        horizontal = randomNumber(0, 1);
        for (int j = 0; j < obsLength; j++)
        {
            if ((p.x + j >= width - 2 && horizontal) || (p.y + j >= height - 2 && !horizontal))
                break;
            map[p.y + (horizontal ? 0 : j)][p.x + (horizontal ? j : 0)] = 'b';
        }
    }
}

void generateMarkers(int howMany, char **map, int width, int height)
{
    for (int i = 0; i < howMany; i++)
    {
        point p = randomEmptyPointOnMap(map, 'v', width, height);
        map[p.y][p.x] = 'm';
    }
}

char **copyMap(char **map, int width, int height)
{
    char **mapCopy = generateEmptyMap(width, height);
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            mapCopy[i][j] = map[i][j];
        }
    }
    return mapCopy;
}

void pointsAccessibleFromPoint(char **mapCopy, int *availableSpots, point curPos)
{
    if (mapCopy[curPos.y][curPos.x] != 'o')
    {
        return;
    }
    mapCopy[curPos.y][curPos.x] = 'v';
    (*availableSpots)++;

    point *neighbouringPoints = neighbourPoints(curPos);
    for (int i = 0; i < 4; i++)
    {
        pointsAccessibleFromPoint(mapCopy, availableSpots, neighbouringPoints[i]);
    }
}

point findSuitableHome(char ***map, int width, int height, int *availableSpots)
{
    point p;
    char **mapCopy;
    int minEmptySquares = 5;
    while (*availableSpots < minEmptySquares)
    {
        *availableSpots = 0;
        p = randomEmptyPointOnMap(*map, 'o', width, height);
        mapCopy = copyMap(*map, width, height);
        pointsAccessibleFromPoint(mapCopy, availableSpots, p);
        if (*availableSpots >= minEmptySquares)
        {
            *map = copyMap(mapCopy, width, height);
        }
    }
    return p;
}

point setHome(char ***map, int width, int height)
{
    int availableSpots = 0;
    point home = findSuitableHome(map, width, height, &availableSpots);
    (*map)[home.y][home.x] = 'h';
    availableSpots--;
    return home;
}

char **generateMap(int width, int height)
{
    char **map = generateEmptyMap(width, height);
    generateWall(map, width, height);
    generateObstacles(map, width, height, (height + width) / 2);
    point home = setHome(&map, width, height);
    generateMarkers((height + width) / 4, map, width, height);
    return map;
}
