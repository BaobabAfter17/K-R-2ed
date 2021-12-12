#include <stdio.h>

#define SIZELIMIT 1000

void itob(int n, char s[], int b);
void reverse(char s[]);

/* test itob */
int main()
{
    int n = 9090;
    int b = 16;
    char s[SIZELIMIT];

    itob(n, s, b);
    printf("%d convert to: %s\n", n, s);
}