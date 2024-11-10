// Written by api on 27-28/10/2024
// This program animates bouncing balls with a checkered background

// To compile: gcc q4.2.c graphics.c -o bouncingBall
// To run: ./bouncingBall | java -jar drawapp-3.0.jar

#include "graphics.h"
#include <stdbool.h>
#include <stdlib.h>

typedef struct canvas
{
    int width;
    int height;
} Canvas;

typedef struct ball
{
    int x;
    int y;
    int width;
    int speed;
    colour colour;
} Ball;

typedef struct direction
{
    bool up;
    bool right;
} Dir;

void drawCheckers(Canvas canvas, bool *isWhite, int squareSize)
{
    for (int y = 0; y < canvas.height; y += squareSize)
    {
        for (int x = 0; x < canvas.width; x += squareSize)
        {
            setColour(*isWhite ? white : black);
            fillRect(x, y, squareSize, squareSize);
            *isWhite = !*isWhite;
        }
        *isWhite = !*isWhite;
    }
}

void drawBackground(Canvas canvas)
{
    background();
    bool isWhite = false;
    int squareSize = canvas.width / 8;
    drawCheckers(canvas, &isWhite, squareSize);
}

void moveBall(Ball *ball, Dir *directions)
{
    int horizontalSign = directions->right ? 1 : -1;
    int verticalSign = directions->up ? -1 : 1;
    ball->x += horizontalSign * ball->speed;
    ball->y += verticalSign * ball->speed;
}

void checkBallDirection(Ball *ball, Canvas canvas, Dir *directions)
{
    if (ball->x + ball->width > canvas.width)
        directions->right = false;
    else if (ball->x < 0)
        directions->right = true;

    if (ball->y + ball->width > canvas.height)
        directions->up = true;
    else if (ball->y < 0)
        directions->up = false;
}

Dir *generateDirections(int size)
{
    Dir *directions = malloc(size * sizeof(Dir));
    for (int i = 0; i < size; i++)
    {
        directions[i].right = true;
        directions[i].up = false;
    }
    return directions;
}

Ball *generateBalls(int size)
{
    Ball *balls = malloc(size * sizeof(Ball));
    for (int i = 0; i < size; i++)
    {
        balls[i].x = i * 50;
        balls[i].y = i * 50;
        balls[i].width = 30;
        balls[i].speed = 1;
        balls[i].colour = green;
    }
    return balls;
}

void drawBalls(Ball *balls, int size)
{
    foreground();
    clear();
    for (int i = 0; i < size; i++)
    {
        setColour(balls[i].colour);
        fillArc(balls[i].x, balls[i].y, balls[i].width, balls[i].width, 0, 360);
    }
    sleep(10);
}

void ControlBalls(int size, Canvas canvas)
{
    Ball *balls = generateBalls(size);
    Dir *directions = generateDirections(size);
    while (true)
    {
        for (int i = 0; i < size; i++)
        {
            checkBallDirection(&balls[i], canvas, &directions[i]);
            moveBall(&balls[i], &directions[i]);
        }
        drawBalls(balls, size);
    }
    free(balls);
    free(directions);
}

int main(void)
{
    Canvas canvas = {600, 680};
    setWindowSize(canvas.width, canvas.height);
    drawBackground(canvas);

    ControlBalls(5, canvas);

    return 0;
}
