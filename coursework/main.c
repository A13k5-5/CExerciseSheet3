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

void turnToDir(robot *robot, enum dirs newDir)
{
    while (robot->dir != newDir)
    {
        right(robot);
    }
}

void moveTo(robot *robot, point newPos, map *map)
{
    if (robot->isFinished)
        return;

    int dx = newPos.x - robot->pos.x;
    int dy = newPos.y - robot->pos.y;

    if (!dx && !dy)
        return;

    enum dirs newDir = dx ? (dx < 0 ? WEST : EAST) : 0;
    newDir = dy ? (dy < 0 ? NORTH : SOUTH) : newDir;
    turnToDir(robot, newDir);
    forward(robot, map);
    drawRobot(robot, map);
}

void end(robot *robot)
{
    robot->isFinished = true;
}

void getHome(robot *robot, map *map)
{
    while (markerCount(robot))
    {
        dropMarker(robot, map);
    }
    end(robot);
}

void setVisited(char **mapCopy, point visitedPoint)
{
    mapCopy[visitedPoint.y][visitedPoint.x] = VISITED;
}

void checkPos(robot *robot, map *map, char lookingFor)
{
    if (lookingFor == MARKER && atMarker(robot, map))
    {
        pickUpMarker(robot, map);
    }
    else if (lookingFor == HOME && isAtHome(robot, map))
    {
        getHome(robot, map);
    }
}

void movingEverywhereRecurAbs(map *map, char **mapCopy, point curPos, robot *robot, char lookingFor)
{
    if (mapCopy[curPos.y][curPos.x] == WALL || mapCopy[curPos.y][curPos.x] == OBSTACLE || mapCopy[curPos.y][curPos.x] == VISITED || robot->isFinished)
    {
        return;
    }
    setVisited(mapCopy, curPos);
    moveTo(robot, curPos, map);
    checkPos(robot, map, lookingFor);

    point *neighbouringPoints = neighbourPoints(robot->pos);
    for (int i = 0; i < 4; i++)
    {
        movingEverywhereRecurAbs(map, mapCopy, neighbouringPoints[i], robot, lookingFor);
        moveTo(robot, curPos, map);
    }
    free(neighbouringPoints);
}

int main(void)
{
    srand(time(NULL));
    int width = randomNumber(8, 14);
    int height = randomNumber(8, 14);
    int squareSize = 50;
    int offset = 50;
    canvas canvas = {width * squareSize + 2 * offset, height * squareSize + 2 * offset, squareSize, offset};
    map map = {
        width,
        height,
        canvas,
        generateMap(width, height)};
    // Starting position can only be a position that can access home
    point startingPos = randomEmptyPointOnMap(map.map, VISITED, width, height);
    resetVisited(map.map, height, width);
    robot robot = {startingPos, randomDir(), 0, false};

    drawBackground(&map);
    char **mapCopy = copyMap(map.map, map.width, map.height);
    movingEverywhereRecurAbs(&map, mapCopy, startingPos, &robot, MARKER);
    freeMap(mapCopy, width, height);
    mapCopy = copyMap(map.map, map.width, map.height);
    movingEverywhereRecurAbs(&map, mapCopy, startingPos, &robot, HOME);
    freeMap(mapCopy, width, height);
    freeMap(map.map, width, height);
    return 0;
}
