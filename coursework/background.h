typedef struct canvas
{
    int width;
    int height;
    int squareSize;
} canvas;

typedef struct point
{
    int x;
    int y;
} point;

void drawGrid(canvas canvas);
int gridToCoords(canvas canvas, int x);
int coordsToGrid(canvas canvas, int x);