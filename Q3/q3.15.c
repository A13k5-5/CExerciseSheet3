// Written by api on 24/10/2024
// This program calculates number of days between two dates in format dd/mm/yyyy

#include <stdio.h>
#include <stdbool.h>
#include "date.h"

void printDate(int *arr)
{
    for (int i = 0; i < 3; i++)
    {
        printf("%i/", arr[i]);
    }
    printf("\n");
}

bool compareArr(int *arr1, int *arr2, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (arr1[i] != arr2[i])
            return false;
    }
    return true;
}

// Assume date2 is later than date1
int daysBetween(char *date1, char *date2)
{
    int counter = 0;

    int date1_[] = {getDay(date1), getMonth(date1), getYear(date1)};
    int date2_[] = {getDay(date2), getMonth(date2), getYear(date2)};
    int curDate[] = {date1_[0], date1_[1], date1_[2]};

    while (true)
    {
        if (compareArr(curDate, date2_, 3) && counter != 0)
            break;
        counter++;
        curDate[0]++;
        if (curDate[0] % (daysInMonth(curDate[1], curDate[2]) + 1) == 0)
        {
            curDate[0] = 1;
            curDate[1]++;
            if (curDate[1] > 12)
            {
                curDate[1] = 1;
                curDate[2]++;
            }
        }
    }
    printf("%i\n", counter);
    return counter;
}

int main(void)
{
    daysBetween("05/08/2005", "05/08/2005");
    return 0;
}