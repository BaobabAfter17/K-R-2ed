#include <stdio.h>

static char buf = 0; /* buffer for ungetch */

int getch(void) /* get a (possible pushed back) character */
{
    int c = (buf != 0) ? buf : getchar();   /* int c to comply with return type */
    buf = 0;
    return c;
}

void ungetch(int c) /* push character back on input */
{
    if (buf > 0)
        printf("ungetch: too many characters\n");
    else
        buf = c;
}
