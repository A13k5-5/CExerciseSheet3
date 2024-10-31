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
    int x[] = {gridToCoords(map, robot->pos.x), gridToCoords(map, robot->pos.x + 1), (gridToCoords(map, robot->pos.x) + gridToCoords(map, robot->pos.x + 1)) / 2};
    int y[] = {gridToCoords(map, robot->pos.y + 1), gridToCoords(map, robot->pos.y + 1), gridToCoords(map, robot->pos.y)};
    setColour(green);
    fillPolygon(3, x, y);
    setColour(black);
    sleep(100);
}

int canMoveForward(robot *robot, map *map)
{
    int sign = robot->dir / abs(robot->dir);
    bool vertical = robot->dir == NORTH || robot->dir == SOUTH;
    return map->map[vertical ? robot->pos.y + sign : robot->pos.y][!vertical ? robot->pos.x + sign : robot->pos.x] != 'w';
}

int atMarker(robot *robot, map *map)
{
    return map->map[robot->pos.y][robot->pos.x] == 'm';
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
void dropMarker() {}
int markerCount() {}
