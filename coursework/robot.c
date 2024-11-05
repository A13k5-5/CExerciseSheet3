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
    // NORTH
    int x[] = {gridToCoords(map, robot->pos.x), gridToCoords(map, robot->pos.x + 1), (gridToCoords(map, robot->pos.x) + gridToCoords(map, robot->pos.x + 1)) / 2};
    int y[] = {gridToCoords(map, robot->pos.y + 1), gridToCoords(map, robot->pos.y + 1), gridToCoords(map, robot->pos.y)};

    // SOUTH
    // int x[] = {gridToCoords(map, robot->pos.x), gridToCoords(map, robot->pos.x + 1), (gridToCoords(map, robot->pos.x) + gridToCoords(map, robot->pos.x + 1)) / 2};
    // int y[] = {gridToCoords(map, robot->pos.y), gridToCoords(map, robot->pos.y), gridToCoords(map, robot->pos.y + 1)};

    // WEST
    // int x[] = {gridToCoords(map, robot->pos.x), gridToCoords(map, robot->pos.x + 1), gridToCoords(map, robot->pos.x + 1)};
    // int y[] = {(gridToCoords(map, robot->pos.y) + gridToCoords(map, robot->pos.y + 1)) / 2, gridToCoords(map, robot->pos.y), gridToCoords(map, robot->pos.y + 1)};

    // EAST
    // int x[] = {gridToCoords(map, robot->pos.x), gridToCoords(map, robot->pos.x), gridToCoords(map, robot->pos.x + 1)};
    // int y[] = {gridToCoords(map, robot->pos.y), gridToCoords(map, robot->pos.y + 1), (gridToCoords(map, robot->pos.y) + gridToCoords(map, robot->pos.y + 1)) / 2};

    setColour(green);
    fillPolygon(3, x, y);
    setColour(black);
    sleep(50);
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
    foreground();
    clear();
    robot->pos.x = newPos.x;
    robot->pos.y = newPos.y;
    drawRobot(robot, map);
    printf("Cur pos: x: %i y: %i\n", newPos.x, newPos.y);
}