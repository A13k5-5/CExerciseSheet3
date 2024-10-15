// Written by Api on 02/10/2024
// This program draws an octagon

// To COMPILE: gcc -o oct graphics.c octagon.c
// To SHOW: ./oct | java -jar drawapp-3.0.jar

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