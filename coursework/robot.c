// This file controls the robot
#include "robot.h"
#include "background.h"
#include "graphics.h"
#include "random.h"
#include "robotDraw.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

void forward(robot *robot, map *map)
{
    if (!canMoveForward(robot, map))
        return;
    int sign = robot->dir / abs(robot->dir);
    bool vertical = robot->dir == NORTH || robot->dir == SOUTH;
    vertical ? (robot->pos.y += sign) : (robot->pos.x += sign);
    drawRobot(robot, map);
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
    drawBackground(map);
    drawRobot(robot, map);
}

int markerCount(robot *robot)
{
    return robot->numMarkersCaried;
}
