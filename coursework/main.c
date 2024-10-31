// This is the main controller

#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include "background.h"
#include "robot.h"
#include "random.h"

// 'v' - visited, 'o' - not visited, 'm' - marker, 'w' - wall

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
    map[4][1] = 'm';
    return map;
}

void findMarkerNextToWall(robot *robot, map *map)
{
    while (!atMarker(robot, map))
    {
        forward(robot, map);
        if (!canMoveForward(robot, map))
        {
            left(robot);
        }
    }
}

int main(void)
{
    int width = 8;
    int height = 8;
    canvas canvas = {500, 500, 50, 50};
    map map = {
        width,
        height,
        canvas,
        generateMap(width, height)};
    point startingPos = {randomNumber(2, map.width - 2), randomNumber(2, map.height - 2)};
    robot robot = {startingPos, randomDir(), 0};
    // printMap(map.map, map.width, map.height);
    drawBackground(&map);
    drawRobot(&robot, &map);
    findMarkerNextToWall(&robot, &map);
    free(map.map);
    return 0;
}
