// Writen by Alex Pison on 02/10/2024
// This program draws a polygon of choice.

// main is commented bcs function draw_polygon is used in sierpinskiTriangle.c
// To draw the heptagon - uncomment the main

#include <stdio.h>
#include <stdlib.h>
#include "graphics.h"
#include <math.h>

void draw_polygon(int num_sides, int side_len, int x, int y)
{
    if (num_sides < 3)
    {
        fprintf(stderr, "Invalid input. A polygon must have at least 3 sides.\n");
        exit(EXIT_FAILURE);
    }

    const float PI = 3.1415926535;
    const float angle_increment = 2 * PI / num_sides;

    int cur_point[] = {x, y};
    int new_point[2];

    for (int i = 1; i < num_sides + 1; i++)
    {
        new_point[0] = cur_point[0] + (int)(side_len * cos(i * angle_increment));
        new_point[1] = cur_point[1] - (int)(side_len * sin(i * angle_increment));
        drawLine(cur_point[0], cur_point[1], new_point[0], new_point[1]);
        cur_point[0] = new_point[0];
        cur_point[1] = new_point[1];
    }
}

// int main(void)
// {
//     draw_polygon(7, 50, 200, 200);
//     return 0;
// }
