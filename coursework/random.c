// This file contains the random function
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "robot.h"

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

    srand(time(NULL));
    result = (rand() % (hi_num - low_num)) + low_num;
    return result;
}

enum dirs randomDir()
{
    enum dirs directions[] = {NORTH, SOUTH, WEST, EAST};
    return directions[randomNumber(0, 3)];
}