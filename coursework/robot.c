// This file controls the robot

#include "robot.h"
#include "background.h"
#include "graphics.h"
#include <stdio.h>
#include <stdlib.h>

void drawRobot(robot *robot, map map)
{
    foreground();
    clear();
    int x[] = {gridToCoords(map, robot->pos.x), gridToCoords(map, robot->pos.x + 1), (gridToCoords(map, robot->pos.x) + gridToCoords(map, robot->pos.x + 1)) / 2};
    int y[] = {gridToCoords(map, robot->pos.y + 1), gridToCoords(map, robot->pos.y + 1), gridToCoords(map, robot->pos.y)};
    setColour(green);
    fillPolygon(3, x, y);
    setColour(black);
    sleep(500);
}

void forward(robot *robot, map map)
{
    int sign = robot->dir / abs(robot->dir);
    if (robot->dir == NORTH || robot->dir == SOUTH)
    {
        robot->pos.y += sign;
    }
    else
    {
        robot->pos.x += sign;
    }
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
int atMarker() {}
int canMoveForward(robot *robot, map map)
{
}
void pickUpMarker() {}
void dropMarker() {}
int markerCount() {}
