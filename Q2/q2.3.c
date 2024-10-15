// Written by api on 08/10/2024
// This program displays a times table of choice using a do while loop

#include <stdio.h>

void times_table(int num)
{
    int i = 1;
    do
    {
        printf("%3i * %3i = %3i\n", i, num, i * num);
    } while (++i < 11);
}

int main(void)
{
    times_table(13);
    return 0;
}