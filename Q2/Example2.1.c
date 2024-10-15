// Written by api on 08/10/2024
// This program writes a message 10 times using while loop

#include <stdio.h>
#include <stdlib.h>

void message(char *msg, int reps)
{
    int i = 1;
    while (i < reps + 1)
    {
        printf("%i: %s\n", i, msg);
        i++;
    }
}

int main(void)
{
    message("Hello World", 10);
    return 0;
}