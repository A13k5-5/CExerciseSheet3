// Written by api on 24/10/2024
// This program verbalises an integer

#include <stdio.h>

void readTens(int num, char ones[][15])
{
    char tens[8][15] = {"twenty", "thirty", "fourty", "fifty", "sixty", "seventy", "eighty", "ninty"};
    int one = num % 10;
    num /= 10;
    printf("%s %s\n", tens[num - 2], ones[one]);
}

void readHundreds(int num, char ones[][15])
{
    int hundreds = num / 100;
    printf("%s %s", ones[hundreds], "hundred");
    readTens(num % 100, ones);
}

void verbaliseInt(int num)
{
    char nums1[20][15] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};

    if (num >= 0 && num < 20)
    {
        printf("%s\n", nums1[num]);
    }
    else if (num >= 20 && num < 100)
    {
        readTens(num, nums1);
    }
    else if (num >= 100 && num < 1000)
    {
        readHundreds(num, nums1);
    }
}

int main(void)
{
    verbaliseInt(21);
    return 0;
}