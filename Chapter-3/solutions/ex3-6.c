#include <stdio.h>

#define abs(x) ((x) < 0 ? -(x) : (x))
#define SIZELIMIT 10

void itoa(int n, char s[], int w);
void reverse(char s[]);

int main()
{
    char sn[SIZELIMIT];
    int n = 67409;
    int w = 10;

    /* test itoa */
    itoa(n, sn, w);
    printf("01234567890123456789\n");
    printf("%s\n", sn);
}

/* itoa: convert n into characters in s, w characters wide*/
void itoa(int n, char s[], int w)
{
    int i, sign;
    void reverse(char s[]);

    sign = n;   /* record sign */
    i = 0;
    do {                          /* generate digits in reverse order */
        s[i++] = abs(n % 10) + '0'; /* get next digit */
    } while ((n /= 10) != 0);   /* delete it */

    if (sign < 0)
        s[i++] = '-';
    while (i < w) /* pad with blanks */
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