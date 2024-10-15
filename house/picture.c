#include "graphics.h"

// To compile: gcc -o pic picture.c graphics.c
// To view, render using Java: ./pic | java -jar drawapp-3.0.jar

int main(void)
{
    // setWindowSize(800, 800);
    // drawArc(150, 150, 50, 50, 0, 360);
    // drawOval(200, 100, 50, 60);
    // drawRect(50, 50, 60, 100);
    drawString("Hello World!", 100, 100);
    return 0;
}
