#include <stdio.h>

int calc(int, char *[]);

/* expr: evaluates a reverse Polish expression */
int main(int argc, char *argv[])
{
    if (argc <= 1)
        printf("Usage: expr expression\n");
    else
        /* TODO: error handling */
        printf("%d\n", calc(argc, argv));
}