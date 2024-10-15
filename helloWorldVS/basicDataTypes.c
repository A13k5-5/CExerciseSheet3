#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int main(void)
{
    int integerVar = 100;
    float floatVar = 331.79;
    double doubleVar = 2.234;
    char charVar = 'a';
    bool boolVar = false;
    long int longVar = 1234567890L;

    printf("integerVar = %i\nfloatVar = %e\ndoubleVar = %g\ncharVar = %c\nboolVar = %i\nlongVar = %li\n",
           integerVar, floatVar, doubleVar, charVar, boolVar, longVar);

    double x = 2.55;
    double result = 3 * pow(x, 3) - 5 * pow(x, 2) + 6;

    printf("The result of x=%f plugged into polynomial 3x^3-5x^2+6 is %f\n", x, result);

    result = (3.31 * pow(10, -8) + 2.01 * pow(10, -7)) / (7.16 * pow(10, -6) + 2.01 * pow(10, -8));
    printf("The result is %g\n", result);

    int i = 12258;
    int j = 7;
    printf("Next multiple is %i\n", i - i % j);
    printf("%i\n", 364 / 7);

    return 0;
}