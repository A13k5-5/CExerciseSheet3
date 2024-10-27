// Written by api on 24/10/2024
// This program validates if a date of format dd/mm/yyyy is valid

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

bool isLeapYear(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int substringToNum(char *string, int start, int len)
{
    char *substring = malloc((len + 1) * sizeof(char));
    strncpy(substring, string + start, len);
    int num = atoi(substring);
    free(substring);
    // printf("number: %i\n", num);
    return num;
}

int getDay(char *date)
{
    return substringToNum(date, 0, 2);
}

int getMonth(char *date)
{
    return substringToNum(date, 3, 2);
}

int getYear(char *date)
{
    return substringToNum(date, 6, 4);
}

int daysInMonth(int month, int year)
{
    return (month > 7 ? month + 1 : month) % 2 == 1 ? 31 : (month == 2 ? (isLeapYear(year) ? 29 : 28) : 30);
}

bool isValidDate(char *date)
{
    int day = getDay(date);
    int month = getMonth(date);
    int year = getYear(date);

    if (month > 12)
        return false;

    int maxDay = daysInMonth(month, year);
    if (day > maxDay)
        return false;
    return true;
}

// int main(void)
// {
//     printf("%d\n", daysInMonth(2, 1900));
//     return 0;
// }