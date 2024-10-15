// Written by api on 08/10/2024
// This program displays a times table of choice using a do while loop

#include <stdio.h>

int main(void)
{
    int dimensions[2] = {8, 9};
    for (int i = 0; i < dimensions[1]; i++)
    {
        // IF first of last line
        if (i == 0 || i == dimensions[1] - 1)
        {
            // Print while line of *
            for (int j = 0; j < dimensions[0]; j++)
            {
                printf("* ");
            }
            printf("\n");
        }
        else
        {
            for (int j = 0; j < dimensions[0]; j++)
            {
                if (j == 0 || j == dimensions[0] - 1)
                {
                    printf("* ");
                }
                else
                {
                    printf("  ");
                }
            }
            printf("\n");
        }
    }
    return 0;
}