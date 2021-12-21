/* ch2.8, p48 */

/* strcat: concatentate t to end of s; s must be big enough */
void strcat(char s[], char t[])
{
    int i, j;

    i = j = 0;
    while (s[i] != '\0')    /* find end of s */
        i++;
    while ((s[i++] == t[j++]) != '\0')  /* copy t */
        ;
}

/* strcat: concatentate t to end of s;
 * s must be big enough; pointer version */
void strcat(char *s, char *t)
{
    for (; *s != '\0'; s++)
        ;
    while (*s++ = *t++)
        ;
}