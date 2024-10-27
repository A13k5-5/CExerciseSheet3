// Written by api on 23/10/2024
// This program determines if an entered long is a palindrome

#include <stdio.h>
#include <stdbool.h>
#include "q3.2.h"

int numDigits(long int num)
{
    int numDigits = 0;
    do
    {
        num /= 10;
        numDigits++;
    } while (num != 0);
    return numDigits;
}

int reverseNum(int num)
{
    int reversed = 0;
    int numDigit = numDigits(num);
    for (int i = numDigit; i > 0; i--)
    {
        reversed += (num % 10) * powRecur(10, i - 1);
        num /= 10;
    }
    return reversed;
}

bool is_palindrome(int num)
{
    return reverseNum(num) == num;
}

int main(void)
{
    int is_palindr = is_palindrome(123431);
    printf("%d\n", is_palindr);
}
