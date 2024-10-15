// Written by api on 03/10/2024
// This program draws cocentric ovals with increasing size

#include "graphics.h"

int main(void)
{
    int width = 1;
    int height = 1;

    while (height < 600 && width < 600)
    {
        drawOval(249 - width / 2, 149 - height / 2, width, height);
        width += 6;
        height += 4;
    }
    return 0;
}