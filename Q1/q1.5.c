// Written by Api on 03/10/2024
// This program draws two rectangles.

#include "graphics.h"

int main(void)
{
    // 1st rectangle
    drawLine(30, 30, 120, 30);
    drawLine(120, 30, 120, 80);
    drawLine(120, 80, 30, 80);
    drawLine(30, 80, 30, 30);

    // 2nd rectangle
    drawRect(150, 50, 60, 140);

    return 0;
}