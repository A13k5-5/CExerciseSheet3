// This is the main controller

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "main.h"
#include "background.h"
#include "robot.h"
#include "random.h"

// 'o' - nothing, 'm' - marker, 'w' - wall, 'h' - home

void printMap(char **map, int width, int height)
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            printf("%c ", map[i][j]);
        }
        printf("\n");
    }
}

void generateWall(char **map, int width, int height)
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (i == 0 || i == height - 1 || j == 0 || j == width - 1)
            {
                map[i][j] = 'w';
            }
        }
    }
}

char **generateEmptyMap(int width, int height)
{
    char **map = (char **)malloc((height) * sizeof(char *));
    for (int i = 0; i < height; i++)
    {
        map[i] = (char *)malloc(width * sizeof(char));
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            map[i][j] = 'o';
        }
    }
    return map;
}

char **generateMap(int width, int height)
{
    char **map = generateEmptyMap(width, height);
    generateWall(map, width, height);
    map[1][1] = 'm';
    map[1][2] = 'h';
    map[2][3] = 'b';
    map[2][5] = 'b';
    map[2][8] = 'b';
    map[4][8] = 'b';
    return map;
}

// Stage 3 function
void findMarkerNextToWall(robot *robot, map *map)
{
    while (1)
    {
        if (!canMoveForward(robot, map))
        {
            left(robot);
        }
        if (atMarker(robot, map))
        {
            pickUpMarker(robot, map);
        }
        if (isAtHome(robot, map) && robot->numMarkersCaried > 0)
        {
            dropMarker(robot, map);
            break;
        }
        forward(robot, map);
    }
}

void findCorner(robot *robot, map *map)
{
    while (canMoveForward(robot, map))
    {
        forward(robot, map);
    }
    right(robot);
    while (canMoveForward(robot, map))
    {
        forward(robot, map);
    }
    // turn around
    right(robot);
    right(robot);
}

bool moveForwardsUntilHitWall(robot *robot, map *map)
{
    while (canMoveForward(robot, map))
    {
        if (atMarker(robot, map))
        {
            pickUpMarker(robot, map);
        }
        if (isAtHome(robot, map) && markerCount(robot) == 1)
        {
            dropMarker(robot, map);
            return true;
        }
        forward(robot, map);
    }
    return false;
}

void goThroughWholeGrid(robot *robot, map *map, bool turnLeft)
{
    while (true)
    {
        if (moveForwardsUntilHitWall(robot, map))
        {
            return;
        }
        turnLeft ? left(robot) : right(robot);
        if (!forward(robot, map))
        {
            turnLeft ? left(robot) : right(robot);
        }
        turnLeft ? left(robot) : right(robot);
        turnLeft = !turnLeft;
    }
}

// Stage 4 function
void findMarkerAnywhere(robot *robot, map *map)
{
    findCorner(robot, map);
    goThroughWholeGrid(robot, map, true);
}

// Stage 5 start
bool checkSide(bool turnLeft, robot *robot, map *map)
{
    turnLeft ? left(robot) : right(robot);
    bool canMoveToSide = canMoveForward(robot, map);
    // Turm back
    turnLeft ? right(robot) : left(robot);
    return canMoveToSide;
}

void goAroundObstacle(robot *robot, map *map)
{
}

int main(void)
{
    int width = randomNumber(5, 15);
    int height = randomNumber(5, 15);
    int squareSize = 50;
    int offset = 50;
    canvas canvas = {width * squareSize + 2 * offset, height * squareSize + 2 * offset, squareSize, offset};
    map map = {
        width,
        height,
        canvas,
        generateMap(width, height)};
    point startingPos = {randomNumber(2, map.width - 2), randomNumber(2, map.height - 2)};
    robot robot = {startingPos, randomDir(), 0};

    drawBackground(&map);
    drawRobot(&robot, &map);
    findMarkerAnywhere(&robot, &map);
    free(map.map);
    return 0;
}
