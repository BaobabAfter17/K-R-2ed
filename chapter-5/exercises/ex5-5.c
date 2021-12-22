/* strncpy: copies at most n characters of t to s */
void my_strncpy(char *s, char *t, int n)
{
    for (; n > 0 && (*s++ = *t++); n--)
        ;
    /* TODO: end of string */
}

/* strncat: concatentate at most n characters of t to end of s */
void my_strncat(char *s, char *t, int n)
{
    while (*s)
        s++;
    for (; n > 0 && (*s++ = *t++); n--)
        ;
    *s = '\0';
}

/* strncmp: compare first n characters of s and t */
int my_strncmp(char *s, char *t, int n)
{
    for (; n > 0 && (*s == *t); n--, s++, t++)
        if (*s == '\0' || *t == '\0')
            break;
    return *s - *t;
}