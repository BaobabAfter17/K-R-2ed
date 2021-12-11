#include <stdio.h>

#define SIZELIMIT 1000

void itoa(int n, char s[], int min_width);
void reverse(char s[]);

int main()
{
    char sn[SIZELIMIT];
    int n = 67409;
    int min_width = 10;

    /* test itoa */
    itoa(n, sn, min_width);
    printf("01234567890123456789\n");
    printf("%s\n", sn);
}

/* itoa: convert n into its string representation */
void itoa(int n, char s[], int min_width)
{
    int i, sign;

    if ((sign = n) < 0) /* record sign */
        n = -n;         /* make n positive */

    i = 0;
    do {                          /* generate digits in reverse order */
        s[i++] = n % 10 + '0'; /* get next digit */
    } while ((n /= 10) > 0);   /* delete it */

    if (sign < 0)   /* add sign */
        s[i++] = '-';
    while (i < min_width)  /* add space if not wide enough */
        s[i++] = ' ';
    s[i] = '\0';

    reverse(s);
}

/* reverse: reverse string s in place*/
void reverse(char s[])
{
    int i, j, temp;

    for (i = 0; s[i] != '\0'; i++) /* reach end of s */
        ;
    i--;
    for (j = 0; j < i; i--, j++)
    {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}