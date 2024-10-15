// Written by api on 08/10/2024
// This program displays a times table of choice using a while loop

#include <stdio.h>

void times_table(int num)
{
    int cur = 0;
    int i = 1;
    while (i < 11)
    {
        cur += num;
        printf("%3i * %3i = %3i\n", i, num, i * num);
        i += 1;
    }
}

int main(void)
{
    times_table(13);
    return 0;
}