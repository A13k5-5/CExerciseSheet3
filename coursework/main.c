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
}

void setVisited(char **mapCopy, point visitedPoint)
{
    mapCopy[visitedPoint.y][visitedPoint.x] = VISITED;
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

void initializeCanvas(canvas *canvas, int width, int height)
{
    canvas->width = width * SQUARE_SIZE + 2 * OFFSET;
    canvas->height = height * SQUARE_SIZE + 2 * OFFSET;
    canvas->squareSize = SQUARE_SIZE;
    canvas->offset = OFFSET;
}

map initializeMap(int width, int height)
{
    canvas canvas;
    initializeCanvas(&canvas, width, height);
    map map = {
        width,
        height,
        canvas,
        generateMap(width, height)};
    return map;
}

robot initializeRobot(map *map)
{
    point startingPos = randomEmptyPointOnMap(map->map, VISITED, map->width, map->height);
    resetVisited(map->map, map->height, map->width);
    robot robot = {startingPos, randomDir(), 0, false};
    return robot;
}

void exploreMap(map *map, robot *robot, char lookingFor)
{
    char **mapCopy = copyMap(map->map, map->width, map->height);
    movingEverywhereRecurAbs(map, mapCopy, robot->pos, robot, lookingFor);
    freeMap(mapCopy, map->width, map->height);
}

void run()
{
    srand(time(NULL));
    int width = randomNumber(MIN_HEIGHT_AND_WIDTH, MAX_HEIGHT_AND_WIDTH);
    int height = randomNumber(MIN_HEIGHT_AND_WIDTH, MAX_HEIGHT_AND_WIDTH);

    map map = initializeMap(width, height);
    robot robot = initializeRobot(&map);

    drawBackground(&map);

    exploreMap(&map, &robot, MARKER);
    exploreMap(&map, &robot, HOME);

    freeMap(map.map, map.width, map.height);
}

int main(void)
{
    run();
    return 0;
}
