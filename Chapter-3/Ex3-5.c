#include <stdio.h>

#define SIZELIMIT 1000

void itob(int n, char s[], int b);
void reverse(char s[]);

/* test itob */
int main()
{
    int n = 9090;
    int b = 16;
    char s[SIZELIMIT];

    itob(n, s, b);
    printf("%d convert to: %s\n", n, s);
}

/* itob: convert n into a base b string representation */
void itob(int n, char s[], int b)
{
    int i, c, sign;

    if ((sign = n) < 0) /* record sign */
        n = -n;         /* make n positive */

    i = 0;
    do {    /* generate digits in reverse order */
        if ((c = n % b) > 9)
            c = c - 10 + 'a';
        else
            c = c + '0';
        s[i++] = c; /* get next digit */
    } while ((n /= b) > 0);   /* delete it */

    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}


/* reverse: reverse string s in place*/
void reverse(char s[])
{
    int i, j, temp;

    for (i = 0; s[i] != '\0'; i++)  /* reach end of s */
        ;
    i--;
    for (j = 0; j < i; i--, j++) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}