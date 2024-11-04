// This is the main controller

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "main.h"
#include "background.h"
#include "robot.h"
#include "random.h"
#include "graphics.h"

// 'o' - nothing, 'm' - marker, 'w' - wall, 'h' - home

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

char **generateMap(int width, int height)
{
    char **map = generateEmptyMap(width, height);
    generateWall(map, width, height);
    map[1][1] = 'm';
    map[1][2] = 'h';
    map[5][4] = 'b';
    map[6][4] = 'b';
    return map;
}

// Stage 3 function
void findMarkerNextToWall(robot *robot, map *map)
{
    while (1)
    {
        if (atMarker(robot, map))
        {
            pickUpMarker(robot, map);
        }
        if (isAtHome(robot, map) && robot->numMarkersCaried > 0)
        {
            dropMarker(robot, map);
            break;
        }
        if (!canMoveForward(robot, map))
        {
            left(robot);
        }
        forward(robot, map);
    }
}

void findCorner(robot *robot, map *map)
{
    while (canMoveForward(robot, map))
    {
        forward(robot, map);
    }
    right(robot);
    while (canMoveForward(robot, map))
    {
        forward(robot, map);
    }
    // turn around
    right(robot);
    right(robot);
}

bool moveForwardsUntilHitWall(robot *robot, map *map)
{
    while (canMoveForward(robot, map))
    {
        if (atMarker(robot, map))
        {
            pickUpMarker(robot, map);
        }
        if (isAtHome(robot, map) && markerCount(robot) == 1)
        {
            dropMarker(robot, map);
            return true;
        }
        forward(robot, map);
    }
    return false;
}

void goThroughWholeGrid(robot *robot, map *map, bool turnLeft)
{
    while (true)
    {
        // if at home and all markers are dropped
        if (moveForwardsUntilHitWall(robot, map))
        {
            return;
        }
        turnLeft ? left(robot) : right(robot);
        if (!forward(robot, map))
        {
            turnLeft ? left(robot) : right(robot);
        }
        turnLeft ? left(robot) : right(robot);
        turnLeft = !turnLeft;
    }
}

// Stage 4 function
void findMarkerAnywhere(robot *robot, map *map)
{
    findCorner(robot, map);
    goThroughWholeGrid(robot, map, true);
}

// Stage 5 start
bool checkSide(bool turnLeft, robot *robot, map *map)
{
    turnLeft ? left(robot) : right(robot);
    bool canMoveToSide = canMoveForward(robot, map);
    // Turn back
    turnLeft ? right(robot) : left(robot);
    return canMoveToSide;
}

void goAroundObstacle(bool turnLeft, robot *robot, map *map)
{
    while (forward(robot, map))
        ;
    turnLeft ? left(robot) : right(robot);
    while (!checkSide(!turnLeft, robot, map))
    {
        forward(robot, map);
    }
    turnLeft ? right(robot) : left(robot);
    forward(robot, map);
    while (!checkSide(!turnLeft, robot, map))
    {
        forward(robot, map);
    }
    turnLeft ? right(robot) : left(robot);
    forward(robot, map);
    while (!checkSide(!turnLeft, robot, map))
    {
        forward(robot, map);
        break;
    }
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
    printMap(mapCopy, map->width, map->height);
    return mapCopy;
}

// Let's try recursion and use a visited map
void movingEverywhere(robot *robot, map *map)
{
    char **mapCopy = copyMap(map);
}

void movingEverywhereRecur(map *map, char **mapCopy, point curPos)
{
    if (map->map[curPos.y][curPos.x])
    {
        return;
    }
}
int main(void)
{
    int width = 10;
    int height = 8;
    int squareSize = 50;
    int offset = 50;
    canvas canvas = {width * squareSize + 2 * offset, height * squareSize + 2 * offset, squareSize, offset};
    map map = {
        width,
        height,
        canvas,
        generateMap(width, height)};
    point startingPos = {1, 6};
    robot robot = {startingPos, EAST, 0};

    drawBackground(&map);
    // drawRobot(&robot, &map);
    // findMarkerAnywhere(&robot, &map);
    // goAroundObstacle(true, &robot, &map);
    free(map.map);
    return 0;
}
