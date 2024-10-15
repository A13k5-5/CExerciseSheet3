// Writen by api 03/10/2024
// This program draws a rainbow.

#include "graphics.h"

int main(void)
{
    const colour colours[] = {red, orange, yellow, green, blue, white};

    int height = 240;

    for (int i = 0; i < 6; i++)
    {
        setColour(colours[i]);
        fillArc(250 - height / 2, 200 - height / 2, height, height, 0, 180);
        height -= 20;
    }
    return 0;
}
