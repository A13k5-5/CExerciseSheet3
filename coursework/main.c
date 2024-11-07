// This is the main controller

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "main.h"
#include "background.h"
#include "robot.h"
#include "random.h"
#include "graphics.h"
#include "map.h"

// 'o' - nothing, 'm' - marker, 'w' - wall, 'h' - home, 'b' - obstacle

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
        if (!canMoveForward(robot, map))
        {
            forward(robot, map);
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
void movingEverywhereRecurAbs(map *map, char **mapCopy, point curPos, robot *robot)
{
    if (mapCopy[curPos.y][curPos.x] != 'o')
    {
        return;
    }
    mapCopy[curPos.y][curPos.x] = 'v';
    moveTo(robot, curPos, map);

    // The next 5 lines can be a separate function
    point north = {curPos.x, curPos.y - 1};
    point south = {curPos.x, curPos.y + 1};
    point west = {curPos.x + 1, curPos.y};
    point east = {curPos.x - 1, curPos.y};
    point neighbourPoints[] = {north, south, west, east};

    for (int i = 0; i < 4; i++)
    {
        movingEverywhereRecurAbs(map, mapCopy, neighbourPoints[i], robot);
        moveTo(robot, curPos, map);
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
    point startingPos = {2, 6};
    robot robot = {startingPos, NORTH, 0};

    drawBackground(&map);
    char **mapCopy = copyMap(&map);
    // printMap(mapCopy, width, height);
    movingEverywhereRecurAbs(&map, mapCopy, startingPos, &robot);
    // drawRobot(&robot, &map);
    // findMarkerAnywhere(&robot, &map);
    // goAroundObstacle(true, &robot, &map);
    free(map.map);
    return 0;
}
