// This file controls the robot

#include "robot.h"
#include "background.h"
#include "graphics.h"
#include "random.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void drawRobot(robot *robot, map *map)
{
    foreground();
    clear();
    int sign = robot->dir / abs(robot->dir);
    bool vertical = robot->dir == NORTH || robot->dir == SOUTH;

    int **x = (int **)malloc(4 * sizeof(int *));
    int **y = (int **)malloc(4 * sizeof(int *));
    for (int i = 0; i < 4; i++)
    {
        x[i] = (int *)malloc(3 * sizeof(int));
        y[i] = (int *)malloc(3 * sizeof(int));
    }
    // NORTH
    int xN[] = {gridToCoords(map, robot->pos.x), gridToCoords(map, robot->pos.x + 1), (gridToCoords(map, robot->pos.x) + gridToCoords(map, robot->pos.x + 1)) / 2};
    int yN[] = {gridToCoords(map, robot->pos.y + 1), gridToCoords(map, robot->pos.y + 1), gridToCoords(map, robot->pos.y)};

    // WEST
    int xW[] = {gridToCoords(map, robot->pos.x), gridToCoords(map, robot->pos.x + 1), gridToCoords(map, robot->pos.x + 1)};
    int yW[] = {(gridToCoords(map, robot->pos.y) + gridToCoords(map, robot->pos.y + 1)) / 2, gridToCoords(map, robot->pos.y), gridToCoords(map, robot->pos.y + 1)};

    // SOUTH
    int xS[] = {gridToCoords(map, robot->pos.x), gridToCoords(map, robot->pos.x + 1), (gridToCoords(map, robot->pos.x) + gridToCoords(map, robot->pos.x + 1)) / 2};
    int yS[] = {gridToCoords(map, robot->pos.y), gridToCoords(map, robot->pos.y), gridToCoords(map, robot->pos.y + 1)};

    // EAST
    int xE[] = {gridToCoords(map, robot->pos.x), gridToCoords(map, robot->pos.x), gridToCoords(map, robot->pos.x + 1)};
    int yE[] = {gridToCoords(map, robot->pos.y), gridToCoords(map, robot->pos.y + 1), (gridToCoords(map, robot->pos.y) + gridToCoords(map, robot->pos.y + 1)) / 2};

    for (int i = 0; i < 3; i++)
    {
        x[0][i] = xN[i];
        y[0][i] = yN[i];
        x[1][i] = xW[i];
        y[1][i] = yW[i];
        x[2][i] = xS[i];
        y[2][i] = yS[i];
        x[3][i] = xE[i];
        y[3][i] = yE[i];
    }

    setColour(green);
    int i = 0;
    switch (robot->dir)
    {
    case NORTH:
        i = 0;
        break;
    case WEST:
        i = 1;
        break;
    case SOUTH:
        i = 2;
        break;
    case EAST:
        i = 3;
        break;
    default:
        break;
    }
    fillPolygon(3, x[i], y[i]);
    setColour(black);
    sleep(1000);
}

bool canMoveForward(robot *robot, map *map)
{
    int sign = robot->dir / abs(robot->dir);
    bool vertical = robot->dir == NORTH || robot->dir == SOUTH;
    char nextPos = map->map[vertical ? robot->pos.y + sign : robot->pos.y][!vertical ? robot->pos.x + sign : robot->pos.x];
    return nextPos != 'w' && nextPos != 'b';
}

int atMarker(robot *robot, map *map)
{
    return map->map[robot->pos.y][robot->pos.x] == 'm';
}

int isAtHome(robot *robot, map *map)
{
    return map->map[robot->pos.y][robot->pos.x] == 'h';
}

// return true if it moved, false if it didn't
bool forward(robot *robot, map *map)
{
    if (!canMoveForward(robot, map))
        return false;
    int sign = robot->dir / abs(robot->dir);
    bool vertical = robot->dir == NORTH || robot->dir == SOUTH;
    vertical ? (robot->pos.y += sign) : (robot->pos.x += sign);
    drawRobot(robot, map);
    return true;
}

void left(robot *robot)
{
    robot->dir = (robot->dir + 2) > EAST ? NORTH : (robot->dir + 2);
}

void right(robot *robot)
{
    robot->dir = (robot->dir - 2) < NORTH ? EAST : (robot->dir - 2);
}

void pickUpMarker(robot *robot, map *map)
{
    if (atMarker(robot, map))
    {
        robot->numMarkersCaried++;
        map->map[robot->pos.y][robot->pos.x] = 'o';
        drawBackground(map);
    }
}

void dropMarker(robot *robot, map *map)
{
    if (robot->numMarkersCaried < 1 || atMarker(robot, map))
        return;
    robot->numMarkersCaried--;
    map->map[robot->pos.y][robot->pos.x] = 'm';
    drawBackground(map);
    drawRobot(robot, map);
}

int markerCount(robot *robot)
{
    return robot->numMarkersCaried;
}

void moveTo(robot *robot, point newPos, map *map)
{
    int dx = newPos.x - robot->pos.x;
    int dy = newPos.y - robot->pos.y;

    if (dx != 0)
    {
        while (robot->dir != (dx > 0 ? EAST : WEST))
        {
            right(robot);
        }
    }
    else if (dy != 0)
    {
        while (robot->dir != (dy > 0 ? SOUTH : NORTH))
        {
            right(robot);
        }
    }
    else
    {
        return;
    }
    forward(robot, map);

    drawRobot(robot, map);
}
