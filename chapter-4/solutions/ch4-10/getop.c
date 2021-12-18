#include <ctype.h>
#include <stdio.h>
#include "calc.h"

#define MAXSIZE 1000

static char line[MAXSIZE];
static int li = 0;
int my_getline(char line[], int lim);

/* getop: get next operator or numeric operand */
int getop(char s[])
{
    int i, c;

    if (line[li] == '\0') {
        if (my_getline(line, MAXSIZE) == 0)
            return EOF;
        else
            li = 0;
    }
    while ((s[0] = c = line[li++]) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.')
        return c; /* not a number */
    i = 0;
    if (isdigit(c)) /* collect integer part */
        while (isdigit(s[++i] = c = line[li++]))
            ;
    if (c == '.') /* collect fration part */
        while (isdigit(s[++i] = c = line[li++]))
            ;
    s[i] = '\0';
    li--;
    return NUMBER;
}
