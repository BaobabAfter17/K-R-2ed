/* p79 */
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <string.h>

#define MAXOP 100   /* max length of a float */

int getch(void);
void ungetch(int);

/* getfloat: get next float from input to *pn */
/* return EOF if reach end of input, 0 if not a number, positive if a number */
int getfloat(float *pn)
{
    int i, c;
    char s[MAXOP];

    while (isspace(c = getch())) /* skip white space */
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.') {
        ungetch(c); /* it is not a number */
        return 0;
    }
    i = 0;
    if (c == '+' || c == '-') { /* record sign in s */
        s[i++] = c;
        c = getch();
    }
    while (c != EOF && isdigit(c)) { /* record integer part in s */
        s[i++] = c;
        c = getch();
    }
    if (c == '.') {
        s[i++] = c;
        c = getch();
    }
    while (c != EOF && isdigit(c)) {    /* record decimal part */
        s[i++] = c;
        c = getch();
    }
    s[i] = '\0';    /* end s */
    if (strlen(s) > 0)
        *pn = atof(s);
    if (c != EOF)
        ungetch(c);
    return c;
}