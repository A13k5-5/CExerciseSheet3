// Written by api on 14/10/2024
// This program draws the Mandelbrot set

#include "graphics.h"
#include <stdio.h>

int getColour(int iterations)
{
    if (iterations == 1000)
    {
        return black; // Black for points inside the Mandelbrot set
    }
    else
    {
        switch (iterations % 13)
        {
        case 0:
            return blue;
        case 1:
            return cyan;
        case 2:
            return darkgray;
        case 3:
            return blue;
        case 4:
            return green;
        case 5:
            return lightgray;
        case 6:
            return magenta;
        case 7:
            return orange;
        case 8:
            return pink;
        case 9:
            return red;
        case 10:
            return white;
        case 11:
            return yellow;
        default:
            return black;
        }
    }
}

void drawMandelbrotSet()
{
    setWindowSize(800, 800);
    double minRe = -2.0, maxRe = 1.0;
    double minIm = -1.5, maxIm = 1.5;
    double reFactor = (maxRe - minRe) / (800 - 1);
    double imFactor = (maxIm - minIm) / (800 - 1);

    for (int Py = 0; Py < 800; Py++)
    {
        double y0 = maxIm - Py * imFactor;
        for (int Px = 0; Px < 800; Px++)
        {
            double x0 = minRe + Px * reFactor;
            double x = 0;
            double y = 0;

            int iteration = 0;
            int max_iter = 1000;

            while (x * x + y * y <= 2 * 2 && iteration < max_iter)
            {
                double xTemp = x * x - y * y + x0;
                y = 2 * x * y + y0;
                x = xTemp;
                iteration++;
            }
            int colour = getColour(iteration);
            setColour(colour);
            drawLine(Px, Py, Px, Py);
        }
    }
}

int main(void)
{
    drawMandelbrotSet();
    return 0;
}