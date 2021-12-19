#include <stdio.h>
#include <math.h>

#define MAXSIZE 1000

void itoa(int n, char s[]);

int main(void) {
    char s[MAXSIZE];
    int n;

    n = -365;
    itoa(n, s);
}

/* itoa: convert an integer into string recursively */
void itoa(int n, char s[]) {
    static int i;
    
    if (n / 10)
        itos(n / 10, s);
    else {
        i = 0;
        if (n < 0)
            s[i++] = '-';
    }
    s[i++] = abs(n) % 10 + '0';
    s[i] = '\0';
}