#include <stdio.h>

#define MAXSIZE 100

void my_strncpy(char *s, char *t, int n);
void my_strncat(char *s, char *t, int n);
int my_strncmp(char *s, char *t, int n);

int main()
{
    char s[] = "hellx,";
    char t[] = "hellx";
    int n = 10;

    printf("%d\n", my_strncmp(s, t, n));
}