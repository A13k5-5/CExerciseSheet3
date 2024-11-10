#pragma once
#include "main.h"
#include "robot.h"
#include "graphics.h"

#define ROBOT_COLOUR green
typedef struct
{
    int x[3];
    int y[3];
} shapeCoords;

void drawRobot(robot *robot, map *map);