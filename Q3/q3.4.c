// Written by api on 23/10/2024
// This program evaluates a multiplication sequence like this 4*7*9*3

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "q3.2.h"

int *splitt(char problem[], char delimiter)
{
    int n = strlen(problem);
    int *numsToBeMultiplied = malloc(sizeof(int) * n);
    int sizeNums = 0;
    char *cur = malloc(100 * sizeof(char));
    int curLen = 0;
    for (int i = 0; i < n; i++)
    {
        if (problem[i] != delimiter)
        {
            cur[curLen] = problem[i];
            curLen++;
        }
        if (i == n - 1 || problem[i] == delimiter)
        {
            numsToBeMultiplied[sizeNums] = atoi(cur);
            sizeNums++;
            memset(cur, ' ', sizeof(cur));
            curLen = 0;
        }
    }
    printArr(numsToBeMultiplied, sizeNums);
    free(cur);
    return numsToBeMultiplied;
}

int multipli(int splited[], int size)
{
    int result = 1;
    for (int i = 0; i < size; i++)
    {
        result *= splited[i];
    }
    return result;
}

int main(void)
{
    int splitted[] = splitt("8*90", '*');
    printf("%i", multipli(splitted, sizeof(splitted) / sizeof(splitted[0])));
    return 0;
}