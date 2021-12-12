/* ex3-5 */

/* itob: convert n into a base b string representation */
void itob(int n, char s[], int b)
{
    int i, c, sign;
    void reverse(char s[]);

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
