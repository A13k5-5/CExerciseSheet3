// Written by api on 08/10/2024
// This program writes a message 10 times using do while

#include <stdio.h>

int main(void)
{
    int n = 1;
    do
    {
        printf("%d: A Message\n", n);
    } while (++n < 11);
    return 0;
}
