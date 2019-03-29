#include <stdio.h>

int main() /* without int generates warning : type specifier missing, defaults to 'int' */
{
    printf("Hello, World\n");
    /* printf("Hello, World\c\n");
     *  warning: unknown escape sequence '\c' */
}

/* cc main.c */

