// Written by api on 24/10/2024
// This program asks for a number to be entered and evaluated if it is a prime

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool isPrime(long int num)
{
    if (num < 4)
        return false;
    for (int i = 2; i < sqrt(num); i++)
    {
        if (num % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main(void)
{
    printf("%d\n", isPrime(2));
    return 0;
}
