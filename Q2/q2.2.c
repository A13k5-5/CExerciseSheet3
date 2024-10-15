// Written by api on 08/10/2024
// This program displays a times table of choice using a for loop

#include <stdio.h>

void times_table(int num)
{
    for (int i = 1; i < 11; i++)
    {
        printf("%3i * %3i = %3i\n", i, num, i * num);
    }
}

int main(void)
{
    times_table(13);
    return 0;
}