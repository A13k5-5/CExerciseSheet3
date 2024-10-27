// Written by api on 21/10/2024
// This program asks the user for side lengths of a triangle and gives its perimeter and area

#include <stdio.h>
#include <math.h>

int calcPerimeter(int sides[])
{
    return sides[0] + sides[1] + sides[2];
}

int calcSemiPerimeter(int sides[])
{
    return calcPerimeter(sides) / 2;
}

int calcArea(int sides[])
{
    int s = calcSemiPerimeter(sides);
    return sqrt(s * (s - sides[0]) * (s - sides[1]) * (s - sides[2]));
}

int main(void)
{
    int sides[3] = {0};
    scanf("%i %i %i", &sides[0], &sides[1], &sides[2]);
    printf("The perimeter is %i\n", calcPerimeter(sides));
    printf("The area is %i\n", calcArea(sides));
    return 0;
}
