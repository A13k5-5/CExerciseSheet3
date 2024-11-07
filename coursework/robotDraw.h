#pragma once
#include "main.h"
#include "robot.h"

typedef struct
{
    int x[3];
    int y[3];
} shapeCoords;

void drawRobot(robot *robot, map *map);