// This file contains the random function
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "robot.h"
#include "main.h"
#include "graphics.h"

// source: https://stackoverflow.com/questions/822323/how-to-generate-a-random-int-in-c/39475626#39475626
int randomNumber(int min_num, int max_num)
{
    int result = 0, low_num = 0, hi_num = 0;

    if (min_num < max_num)
    {
        low_num = min_num;
        hi_num = max_num + 1; // include max_num in output
    }
    else
    {
        low_num = max_num + 1; // include max_num in output
        hi_num = min_num;
    }

    result = (rand() % (hi_num - low_num)) + low_num;
    return result;
}

enum dirs randomDir()
{
    enum dirs directions[] = {NORTH, SOUTH, WEST, EAST};
    return directions[randomNumber(0, 3)];
}

int *generateRandomNumbers(int size, int min, int max)
{
    int *arr = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++)
    {
        arr[i] = randomNumber(min, max);
    }
    return arr;
}

point generateRandomPoint(int width, int height)
{
    point p = {randomNumber(1, width - 2), randomNumber(1, height - 2)};
    return p;
}

point randomEmptyPointOnMap(char **map, int width, int height)
{
    bool isEmpty = false;
    point p;
    while (!isEmpty)
    {
        p = generateRandomPoint(width, height);
        if (map[p.y][p.x] == 'o')
        {
            isEmpty = true;
        }
    }
    return p;
}