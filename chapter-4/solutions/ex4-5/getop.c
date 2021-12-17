#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define NUMBER '0'  /* signal that a number was found */
#define NAME 'n'    /* signal that a name was found */

int getch(void);
void ungetch(int);


/* getop: get next operator, numeric operand or math func  */
int getop(char s[])
{
    int c, i;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    i = 0;
    if (islower(c))
    {
        while (islower(s[++i] = c = getch()))
            ;
        s[i] = '\0';
        if (c != EOF)
            ungetch(c); /* went one char too far */
        if (strlen(s) > 1)
            return NAME;    /* > 1 char, it is name */
        else
            return c;   /* it may be a command */
    }
    if (!isdigit(c) && c != '.')
        return c;   /* not a number */
    if (isdigit(c))
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}