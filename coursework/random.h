#pragma once
#include "robot.h"

int randomNumber(int min_num, int max_num);
enum dirs randomDir();
int *generateRandomNumbers(int size, int min, int max);
point generateRandomPoint(int width, int height);