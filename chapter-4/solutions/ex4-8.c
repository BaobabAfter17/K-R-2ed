#include <stdio.h>

char buf = 0;

/* getch: get a (possible pushed back) character */
int getch(void)
{
    int c;

    if (buf != 0)
        c = buf;
    else
        c = getchar();
    buf = 0;
    return c;
}

/* ungetch: push character back to input */
void ungetch(char c)
{
    if (buf != 0)
        printf("ungetch: too many characters\n");
    else
        buf = c;
}