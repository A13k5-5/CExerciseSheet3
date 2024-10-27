// Written by api on 27/10/2024
// This code is from COMP0002 presentation on pointers

#include <stdio.h>

struct point
{
    int x;
    int y;
};

struct point updatePoint(struct point p, int x, int y)
{
    p.x = x;
    p.y = y;
    return p;
}

void useUpdatePoint()
{
    struct point p1 = {1, 2}; // Initialisation of a struct - a two-part name
    p1.x = 2;                 // dot operator used to access each value
    p1.y = 4;
    printf("%i\n", p1.x);
    p1 = updatePoint(p1, 3, 4);
    printf("%i\n", p1.x);
}

void arrayStructs()
{
    struct point points[10];
    points[0].x = 5;
    points[0].y = 6;
}

int main(void)
{
    useUpdatePoint();
    return 0;
}