/* strcat: concatentate t to end of s; pointer version */
void strcat(char *s, char *t)
{
    while (*s)
        s++;
    while (*s++ = *t++)
        ;
}