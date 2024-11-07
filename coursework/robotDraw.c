#include "robotDraw.h"
#include "background.h"
#include "main.h"
#include "robot.h"
#include "graphics.h"

void getNorthCoords(robot *robot, map *map, shapeCoords *coords)
{
    coords->x[0] = gridToCoords(map, robot->pos.x);
    coords->x[1] = gridToCoords(map, robot->pos.x + 1);
    coords->x[2] = (gridToCoords(map, robot->pos.x) + gridToCoords(map, robot->pos.x + 1)) / 2;
    coords->y[0] = gridToCoords(map, robot->pos.y + 1);
    coords->y[1] = gridToCoords(map, robot->pos.y + 1);
    coords->y[2] = gridToCoords(map, robot->pos.y);
}

void getSouthCoords(robot *robot, map *map, shapeCoords *coords)
{
    coords->x[0] = gridToCoords(map, robot->pos.x);
    coords->x[1] = gridToCoords(map, robot->pos.x + 1);
    coords->x[2] = (gridToCoords(map, robot->pos.x) + gridToCoords(map, robot->pos.x + 1)) / 2;
    coords->y[0] = gridToCoords(map, robot->pos.y);
    coords->y[1] = gridToCoords(map, robot->pos.y);
    coords->y[2] = gridToCoords(map, robot->pos.y + 1);
}

void getEastCoords(robot *robot, map *map, shapeCoords *coords)
{
    coords->x[0] = gridToCoords(map, robot->pos.x);
    coords->x[1] = gridToCoords(map, robot->pos.x);
    coords->x[2] = gridToCoords(map, robot->pos.x + 1);
    coords->y[0] = gridToCoords(map, robot->pos.y);
    coords->y[1] = gridToCoords(map, robot->pos.y + 1);
    coords->y[2] = (gridToCoords(map, robot->pos.y) + gridToCoords(map, robot->pos.y + 1)) / 2;
}

void getWestCoords(robot *robot, map *map, shapeCoords *coords)
{
    coords->x[0] = gridToCoords(map, robot->pos.x + 1);
    coords->x[1] = gridToCoords(map, robot->pos.x + 1);
    coords->x[2] = gridToCoords(map, robot->pos.x);
    coords->y[0] = gridToCoords(map, robot->pos.y);
    coords->y[1] = gridToCoords(map, robot->pos.y + 1);
    coords->y[2] = (gridToCoords(map, robot->pos.y) + gridToCoords(map, robot->pos.y + 1)) / 2;
}

shapeCoords getShapeCoords(robot *robot, map *map)
{
    shapeCoords coords;
    switch (robot->dir)
    {
    case NORTH:
        getNorthCoords(robot, map, &coords);
        break;
    case SOUTH:
        getSouthCoords(robot, map, &coords);
        break;
    case WEST:
        getWestCoords(robot, map, &coords);
        break;
    case EAST:
        getEastCoords(robot, map, &coords);
        break;
    }
    return coords;
}

void drawRobot(robot *robot, map *map)
{
    foreground();
    clear();

    shapeCoords coords = getShapeCoords(robot, map);
    setColour(green);
    fillPolygon(3, coords.x, coords.y);
    setColour(black);
    sleep(100);
}