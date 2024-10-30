enum dirs
{
    NORTH,
    EAST,
    SOUTH,
    WEST
};

typedef struct robot
{
    int x;
    int y;
    enum dirs dir;
} robot;