// Writen by Alex Pison 02/10/2024
// This program draws an octagon.

// I did the calculations myself and noticed the example rounded some numbers to
// the "nicer" divisibe by 5 number like 170.71 to 170 even though it should be 171.

#include "graphics.h"

int main(void)
{
    drawLine(50, 50, 100, 50);
    drawLine(100, 50, 135, 85);
    drawLine(135, 85, 135, 135);
    drawLine(135, 135, 100, 171);
    drawLine(100, 171, 50, 171);
    drawLine(50, 171, 14, 135);
    drawLine(14, 135, 14, 85);
    drawLine(14, 85, 50, 50);
    return 0;
}