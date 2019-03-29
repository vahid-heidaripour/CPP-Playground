#include <stdio.h>

int main()
{
    float a = 2.3;
    int b = 2;

    printf("%d\t%d\n", a, b);
    /* the output is 2 \t some initial value for b
     * this happens because of %d for a float variable
     * and compiler generates a warning */

    printf("%f\t%d\n", a, b);

    /* Output is:
     * 2       -448165504
     * 2.300000        2 */
}