#include <string.h>

/* ungets: push string back onto input */
void ungets(char s[])
{
    int len = strlen(s);
    void ungetch(char);

    while (len > 0)
        ungetch(s[--len]);
}