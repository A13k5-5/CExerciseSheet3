#pragma once
#include "main.h"
#include <stdbool.h>
// Everytime there is a change in direction, either 2 is added or substracted
enum dirs
{
    NORTH = -3,
    WEST = -1,
    SOUTH = 1,
    EAST = 3
};

typedef struct robot
{
    point pos;
    enum dirs dir;
    int numMarkersCaried;
} robot;

void drawRobot(robot *robot, map *map);
bool forward(robot *robot, map *map);
void left(robot *robot);
void right(robot *robot);
int atMarker(robot *robot, map *map);
bool canMoveForward(robot *robot, map *map);
void pickUpMarker(robot *robot, map *map);
int isAtHome(robot *robot, map *map);
void dropMarker(robot *robot, map *map);
int markerCount(robot *robot);