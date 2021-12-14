/* ex3-6 from C anwser book */

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