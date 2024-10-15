// Written by api on 08/10/2024
// This program writes a message 10 times using for loop

#include <stdio.h>

void message(char *msg, int reps)
{
    for (int i = 1; i < reps + 1; i++)
    {
        printf("%i: %s\n", i, msg);
    }
}

int main(void)
{
    message("Hello World", 10);
    return 0;
}