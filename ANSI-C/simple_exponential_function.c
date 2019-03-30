#include <stdio.h>

/* function declaration - no memory allocation */
int power(int m, int y);  /* x ^ y */
/* if we don't write the definition of the function, it's not a problem */

int main()
{
    int i;

    for (i = 0; i < 10; ++i)
        printf("%d %d %d\n", i, power(2, i), power(-3, i));

    return 0;
}

/* function definition - memory allocation */
int power(int base, int n)
{
    int i, p;

    p = 1;
    for (i = 1; i <= n; ++i)
        p *= base;

    return p;
}
