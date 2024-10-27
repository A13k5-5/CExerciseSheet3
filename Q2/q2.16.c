// Written by api on 17/10/2024
// This program calculates cases where we insert + or - to 123456789 to get sum of 100

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

// Between each gap, there are three options - no sign, plus or minus
// I now have to take into considerations all the cases - that is 3^8 cases - not that much
// Since only digits 1-9 are used, I am using digits -2, -1, and 0 to represent an empty element, +, and -.

int calculatRow(int row[], int size)
{
    int cur = 0;
    char *curStr = malloc(12 * sizeof(char));
    int curStrLen = 0;
    int sign = 1;

    for (int i = 0; i < size; i++)
    {
        if (row[i] > 0)
        {
            curStr[curStrLen] = row[i] + '0';
            curStrLen++;
        }
        else if (row[i] == -1)
        {
            cur += sign * atoi(curStr);
            curStrLen = 0;
            memset(curStr, ' ', sizeof(curStr)); // Clear the string
            sign = 1;
        }
        else if (row[i] == 0)
        {
            cur += sign * atoi(curStr);
            curStrLen = 0;
            memset(curStr, ' ', sizeof(curStr));
            sign = -1;
        }
        if (i == size - 1)
        {
            cur += sign * atoi(curStr);
        }
    }
    free(curStr);
    return cur;
}

void printArr(int num[], int size)
{
    const char *signs[] = {"", " + ", " - "};
    for (int i = 0; i < size; i++)
    {
        if (num[i] <= 0)
        {
            printf("%s", signs[num[i] + 2]);
        }
        else
        {
            printf("%i", num[i]);
        }
    }
}

void addSigns(int pos, int size, int numbers[], int signs[], int goalValue)
{
    if (pos == size)
        return;

    for (int i = 0; i < 3; i++)
    {
        numbers[pos] = signs[i];
        addSigns(pos + 2, size, numbers, signs, goalValue);
        if (pos == size - 2)
        {
            int result = calculatRow(numbers, size);
            if (result == goalValue)
            {
                printArr(numbers, size);
                printf(" = %i\n", result);
            }
        }
    }
}

int main(void)
{
    int numbers[] = {1, 0, 2, 0, 3, 0, 4, 0, 5, 0, 6, 0, 7, 0, 8, 0, 9};
    int numLength = sizeof(numbers) / sizeof(int);
    int signs[] = {0, -1, -2};
    int goalValue = 100;
    addSigns(1, numLength, numbers, signs, goalValue);

    return 0;
}