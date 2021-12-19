/* chapter 4.3, p78 */
#include <ctype.h>
#include <stdio.h>

#define NUMBER '0'

/* getop: get next operator or numeric operand */
int getop(char s[])
{
    int i, c;
    static int lastc = 0;

    if (lastc != 0) {
        c = lastc;
        lastc = 0;
    } else
        c = getchar();
    while ((s[0] = c) == ' ' || c == '\t')
        c = getchar();
    s[1] = '\0';
    if (!isdigit(c) && c != '.')
        return c; /* not a number */
    i = 0;
    if (isdigit(c)) /* collect integer part */
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.') /* collect fration part */
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        lastc = c;
    return NUMBER;
}