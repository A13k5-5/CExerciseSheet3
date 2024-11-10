#pragma once
#include "robot.h"

int randomNumber(int min_num, int max_num);
enum dirs randomDir();
point generateRandomPoint(int width, int height);
point randomEmptyPointOnMap(char **map, char empty, int width, int height);