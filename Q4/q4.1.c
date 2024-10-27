// Writen by api on 24/10/2024
// This program draws a simple animation

// To compile: gcc q4.1.c graphics.c -o revolvingSquare -lm
// To run: ./revolvingSquare | java -jar drawapp-3.0.jar

#include "graphics.h"
#define _USE_MATH_DEFINES
#include <math.h>

typedef struct point
{
    int x;
    int y;
} Point;

typedef struct circle
{
    Point p;
    int r;
} Circle;

void drawCircle(Circle c)
{
    background();
    setColour(green);
    fillArc(c.p.x - c.r, c.p.y - c.r, 2 * c.r, 2 * c.r, 0, 360);
    setColour(white);
    fillArc(c.p.x - c.r / 2, c.p.y - c.r / 2, c.r, c.r, 0, 360);
    setColour(black);
}

void drawCirclingSquare(int size, Circle c)
{
    foreground();
    double theta = 0;

    while (1)
    {
        setColour(blue);
        fillRect(c.p.x + c.r * cos(theta) - size / 2, c.p.y + c.r * sin(theta) - size / 2, size, size);
        theta += 2.0 * M_PI / 360;
        sleep(10);
        clear();
    }
}

int main(void)
{
    Circle c = {{150, 150}, 100};
    drawCircle(c);
    drawCirclingSquare(50, c);
    return 0;
}