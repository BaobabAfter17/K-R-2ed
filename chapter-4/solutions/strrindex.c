/* ex4-1, from C anwser book, p69 */
#include <string.h>

/* strrindex: return rightmost index of t in s, -1 if nont */
int strrindex(char s[], char t[])
{
    int i, j, k;

    for (i = strlen(s) - strlen(t); i >= 0; i--) {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
            ;
        if (k > 0 && t[k] == '\0')
            return i;
    }
    return -1;
}