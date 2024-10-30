// This is the main controller

#include <stdlib.h>
#include <stdio.h>
#include "main.h"
#include "background.h"
#include "robot.h"

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

char **generateEmptyGrid(int width, int height)
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
    char **map = generateEmptyGrid(width, height);
    generateWall(map, width, height);
    map[1][1] = 'm';
    return map;
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
    point startingPos = {1, 1};
    robot robot = {startingPos, NORTH};
    // printMap(map.map, map.width, map.height);
    drawBackground(map);
    drawRobot(&robot, map);
    forward(&robot, map);
    forward(&robot, map);
    forward(&robot, map);
    forward(&robot, map);

    free(map.map);
    return 0;
}