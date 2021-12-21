/* strend: return 1 if s end with t, 0 otherwise */
int strend(char *s, char *t)
{
    int len;

    for (len = 0; *t++; len++)
        ;
    while (*s++)
        ;
    while (*t-- == *s--)
        len--;
    return len == 0; 
}