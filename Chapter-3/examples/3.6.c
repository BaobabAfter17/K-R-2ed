#include <stdio.h>

#define SIZELIMIT 1000

void itoa(int n, char s[]);
void reverse(char s[]);

int main()
{
    char sn[SIZELIMIT];
    char s[] = "Hello, world!!";
    int n = 67409;

    /* test reverse */
    printf("Before reverse: %s\n", s);
    reverse(s);
    printf("After reverse: %s\n", s);

    /* test itoa */
    itoa(n, sn);
    printf("%d after converted: %s\n", n, sn);
}

/* itoa: convert n into its string representation */
void itoa(int n, char s[])
{
    int i, sign;

    if ((sign = n) < 0) /* record sign */
        n = -n;         /* make n positive */

    i = 0;
    do {                          /* generate digits in reverse order */
        s[i++] = n % 10 + '0'; /* get next digit */
    } while ((n /= 10) > 0);   /* delete it */

    if (sign < 0)
        s[i++] = '-';
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
    for (j = 0; j < i; i--, j++) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}