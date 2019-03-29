#include <stdio.h>

int main()
{
    float a = 12345.1234566678;

    printf("%f\n%6f\n%.2f\n%6.2f\n", a, a, a, a);
}

/*
 * The output is :
 * 12345.123047 ==> default %f has 6 digits after decimal point
 * 12345.123047
 * 12345.12
 * 12345.12
 */