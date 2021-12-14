#include <stdio.h>

int strrindex(char s[], char t[]);

/* test strrindex */
int main()
{
    char s[] = "how could we ould he";
    char t[] = "ould";
    int index = strrindex(s, t);
    printf("%d", index);
}