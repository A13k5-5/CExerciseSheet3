// Written by api on 27/10/2024
// This program animates a bouncing ball with a checkered background

// To compile: gcc q4.2.c graphics.c -o bouncingBall
// To run: ./bouncingBall | java -jar drawapp-3.0.jar

#include "graphics.h"
#include <stdbool.h>

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

void drawBall(Ball ball)
{
    foreground();
    clear();
    setColour(ball.colour);
    fillArc(ball.x, ball.y, ball.width, ball.width, 0, 360);
}

void moveBall(Ball *ball, Dir *directions)
{
    int horizontalSign = directions->right ? 1 : -1;
    int verticalSign = directions->up ? -1 : 1;
    ball->x += horizontalSign * ball->speed;
    ball->y += verticalSign * ball->speed;
    drawBall(*ball);
    sleep(10);
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

void controlBall(Ball *ball, Canvas canvas)
{
    Dir directions = {false, true};
    while (true)
    {
        checkBallDirection(ball, canvas, &directions);
        moveBall(ball, &directions);
    }
}

int main(void)
{
    Canvas canvas = {600, 680};
    setWindowSize(canvas.width, canvas.height);
    drawBackground(canvas);

    Ball ball = {300, 150, 30, 3, green};
    controlBall(&ball, canvas);
    return 0;
}