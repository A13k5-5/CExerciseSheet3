// Written by api on 05/10/2024
// This program draws the Sierpinski Triangle

#include "graphics.h"
#include <math.h>

void sierpinskiTriangle(int depth, int side_len, int x, int y)
{
    void draw_polygon(int num_sides, int side_len, int x, int y);

    if (depth == 0)
    {
        draw_polygon(3, side_len, x, y);
    }
    else
    {
        sierpinskiTriangle(depth - 1, side_len / 2, x, y);
        sierpinskiTriangle(depth - 1, side_len / 2, x + side_len / 2, y);
        sierpinskiTriangle(depth - 1, side_len / 2, x + side_len / 4, y - sqrt(3) * side_len / 4.0);
    }
}

int main(void)
{
    sierpinskiTriangle(5, 200, 150, 250);
    return 0;
}