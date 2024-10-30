// This is the main controller

#include <stdlib.h>
#include <stdio.h>

// 'v' - visited, 'o' - not visited, 'm' - marker, 'w' - wall

void printMap(char **map, int width, int height)
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            printf("%c ", map[i][j]);
        }
        printf("\n");
    }
}

char **generateMap(int width, int height)
{
    char **map = (char **)malloc((height) * sizeof(char *));
    for (int i = 0; i < height; i++)
    {
        map[i] = (char *)malloc(width * sizeof(char));
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            map[i][j] = 'o';
        }
    }
    return map;
}

void generateWall(char **map, int width, int height)
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (i == 0 || i == height - 1 || j == 0 || j == width - 1)
            {
                map[i][j] = 'w';
            }
        }
    }
}

int main(void)
{
    int width = 8;
    int height = 8;
    char **map = generateMap(width, height);
    printMap(map, width, height);
    printf("\n");
    generateWall(map, width, height);
    printMap(map, width, height);
    return 0;
}