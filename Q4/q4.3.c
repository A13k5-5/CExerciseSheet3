// Written by api on 28/10/2024
// This program is my implementation of stringCopy function - from COMP0002 slides

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *stringCopy(char *s)
{
    char *to = malloc(strlen(s) * sizeof(char));
    int i = 0;
    while (to[i] = s[i])
    {
        i++;
    }
    return to;
}

int main(void)
{
    char *to = stringCopy("hello");
    printf("%s\n", to);
    free(to);
    return 0;
}
