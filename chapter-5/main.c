#include <stdio.h>

int main()
{
    char (*p)[] = {"hello", "world", "again"};

    printf("%lu", sizeof(*p));
}