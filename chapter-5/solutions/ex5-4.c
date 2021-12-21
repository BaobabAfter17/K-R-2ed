/* strend: return 1 if s end with t */
int strend(char *s, char *t)
{
    char *bs = s;   /* remember beginning of strs */
    char *bt = t;

    for (; *s; s++) /* end of s */
        ;
    for (; *t; t++) /* end of t */
        ;
    for (; *s == *t; s--, t--)
        if (t == bt || s == bs)
            break;  /* at beginning of str */
    if (*s == *t && t == bt && *s != '\0')
        return 1;
    else
        return 0;    
}