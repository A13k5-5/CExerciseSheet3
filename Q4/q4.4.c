// Written by api on 28/10/2024
//

#include <stdio.h>
#include <string.h>

int strend(char *s, char *t)
{
    if (strlen(t) > strlen(s))
    {
        return 0;
    }

    int i = 0;
    long int len = strlen(s) - strlen(t);
    while (*s++)
    {
        i++;
        if (i == len)
            break;
    }
    return !strcmp(s, t);
}

int main(void)
{
    printf("%i\n", strend("hello", "hello"));
    return 0;
}