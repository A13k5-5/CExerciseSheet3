// Written by api on 07/10/2024
// This program rewrites each digit of input number into a word

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    char *digitWords[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    char *number = malloc(100 * sizeof(char));

    printf("Enter a number:\n");
    scanf("%99s", number);

    for (int i = 0; i < strlen(number); i++)
    {
        printf("%s ", digitWords[number[i] - '0']);
    }
    printf("\n");

    return 0;
}
