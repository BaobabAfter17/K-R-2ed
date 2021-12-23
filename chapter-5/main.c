#include <stdio.h>

#define MAXSIZE 100

double atof(char *);

int main()
{
    char s[] = "1.2901";

    printf("%g\n", atof(s));
}