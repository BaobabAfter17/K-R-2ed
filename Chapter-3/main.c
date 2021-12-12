#include <stdio.h>

int trim(char s[]);

/* test itob */
int main()
{
    char s[] = "abd    ";
    int n;

    n = trim(s);
    printf("%d, |%s|\n", n, s);
}