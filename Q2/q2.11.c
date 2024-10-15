// Written by api on 14/10/2024
// This program prints out squares, even squares, and primes.

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

void printSquares(int max)
{
    for (int i = 1; i < max + 1; i++)
    {
        printf("%i\n", i * i);
    }
}

void printEvenSquares(int max)
{
    for (int i = 2; i < max + 1; i += 2)
    {
        printf("%i\n", i * i);
    }
}

void printPrimes(int max)
{
    for (int j = 2; j <= max; j++)
    {
        bool isPrime = true;
        for (int i = 2; i <= sqrt(j) && isPrime; i++)
        {
            isPrime = !(j % i == 0);
        }
        if (isPrime)
        {
            printf("%i\n", j);
        }
    }
}

int main(void)
{
    // printSquares(100);
    // printEvenSquares(100);
    printPrimes(101);

    return 0;
}