#pragma once
#include "main.h"
// Two positive two negative - important for determining where the robot should move
enum dirs
{
    NORTH = -3,
    WEST = -1,
    SOUTH = 1,
    EAST = 3
};
typedef struct point
{
    int x;
    int y;
} point;
typedef struct robot
{
    point pos;
    enum dirs dir;
} robot;

void drawRobot(robot *robot, map map);
void forward(robot *robot, map map);
void left(robot *robot);
void right(robot *robot);