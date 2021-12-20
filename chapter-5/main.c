#include <stdio.h>

#define SIZE 100 /* size of float array */

int getfloat(float *);

/* test getfloat */
int main()
{
    int n, getfloat(float *);
    float array[SIZE];

    for (n = 0; n < SIZE && getfloat(&array[n]) != EOF; n++)
        printf("%f\n", array[n]);
}