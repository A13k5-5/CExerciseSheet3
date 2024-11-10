#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "main.h"
#include "map.h"
#include "random.h"

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
            map[i][j] = EMPTY;
        }
    }
    return map;
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

void freeMap(char **map, int width, int height)
{
    for (int i = 0; i < height; i++)
    {
        free(map[i]);
    }
    free(map);
}

void resetVisited(char **map, int height, int width)
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (map[i][j] == VISITED)
            {
                map[i][j] = EMPTY;
            }
        }
    }
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

void generateEdgeWall(char **map, int width, int height)
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (i == 0 || i == height - 1 || j == 0 || j == width - 1)
            {
                map[i][j] = WALL;
            }
        }
    }
}

void generateIrregularWall(char **map, int width, int height, point curPos, int depth)
{
    if (curPos.x < 0 || curPos.x >= width - 1 || curPos.y < 0 || curPos.y >= height - 1)
    {
        return;
    }
    map[curPos.y][curPos.x] = WALL;
    point *neighbouringPoints = neighbourPoints(curPos);

    for (int i = 0; i < 4; i++)
    {
        if ((randomNumber(0, 2) == 0 && depth < 8) || !depth)
        {
            generateIrregularWall(map, width, height, neighbouringPoints[i], depth + 1);
        }
    }
    free(neighbouringPoints);
}

void generateWall(char **map, int width, int height)
{
    generateEdgeWall(map, width, height);
    point start = {1, 1};
    generateIrregularWall(map, width, height, start, 0);
    point start2 = {width - 2, 1};
    generateIrregularWall(map, width, height, start2, 0);
}

void generateObstacle(char **map, int width, int height)
{
    point p = randomEmptyPointOnMap(map, EMPTY, width, height);
    int obsLength = randomNumber(MIN_OBSTALCE_LEN, MAX_OBSTALCE_LEN);
    bool horizontal = randomNumber(false, true);
    for (int j = 0; j < obsLength; j++)
    {
        if ((p.x + j >= width - 2 && horizontal) || (p.y + j >= height - 2 && !horizontal))
            break;
        map[p.y + (horizontal ? 0 : j)][p.x + (horizontal ? j : 0)] = OBSTACLE;
    }
}

void generateObstacles(char **map, int width, int height, int howMany)
{
    for (int i = 0; i < howMany; i++)
    {
        generateObstacle(map, width, height);
    }
}

void generateMarkers(int howMany, char **map, int width, int height)
{
    for (int i = 0; i < howMany; i++)
    {
        point p = randomEmptyPointOnMap(map, VISITED, width, height);
        map[p.y][p.x] = MARKER;
    }
}

// Sets all accessible points to VISITED
void pointsAccessibleFromPoint(char **mapCopy, int *availableSpots, point curPos)
{
    if (mapCopy[curPos.y][curPos.x] != EMPTY)
    {
        return;
    }
    mapCopy[curPos.y][curPos.x] = VISITED;
    (*availableSpots)++;

    point *neighbouringPoints = neighbourPoints(curPos);
    for (int i = 0; i < 4; i++)
    {
        pointsAccessibleFromPoint(mapCopy, availableSpots, neighbouringPoints[i]);
    }
    free(neighbouringPoints);
}

point findSuitableHome(char ***map, int width, int height)
{
    point p;
    char **mapCopy;
    int minEmptySquares = 5, availableSpots = 0;
    while (availableSpots < minEmptySquares)
    {
        availableSpots = 0;
        p = randomEmptyPointOnMap(*map, EMPTY, width, height);
        mapCopy = copyMap(*map, width, height);

        pointsAccessibleFromPoint(mapCopy, &availableSpots, p);
        if (availableSpots >= minEmptySquares)
        {
            freeMap(*map, width, height);
            *map = copyMap(mapCopy, width, height);
        }
        freeMap(mapCopy, width, height);
    }
    return p;
}

void setHome(char ***map, int width, int height)
{
    point home = findSuitableHome(map, width, height);
    (*map)[home.y][home.x] = HOME;
}

char **generateMap(int width, int height)
{
    char **map = generateEmptyMap(width, height);
    generateWall(map, width, height);
    generateObstacles(map, width, height, (height + width) / 2);
    setHome(&map, width, height);
    generateMarkers((height + width) / 4, map, width, height);
    return map;
}
