/* ex3-5 from C answer book */

/* itob: convert n to characters in s - base b */
void itob(int n, char s[], int b)
{
    int i, j, sign;
    void reverse(char s[]);

    if ((sign = n) < 0) /* record sign */
        n = -n;
    i = 0;
    do {    /* generate digits in reverse order */
        j = n % b;
        s[i++] = (j <= 9) ? j+'0' : j+'a'-10;  /* get next digit */
    } while ((n /= b) > 0);  /* delete it */
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}