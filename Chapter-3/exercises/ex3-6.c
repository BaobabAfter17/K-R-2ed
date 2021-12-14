/* ex3-6 */

/* itoa: convert n into its string representation */
void itoa(int n, char s[], int min_width)
{
    int i, sign;
    void reverse(char s[]);

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