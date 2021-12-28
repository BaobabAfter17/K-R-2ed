# ch5-8, p113
What's the difference?
```
int *p;     /* p is a pointer to integer; p is an integer pointer */
int p[];    /* p is an array of integers */
int *p[];   /* int* p[]; p is an array of pointers to integers */
int (*p)[13];   /* p is a pointer to an array of 13 integers */

char *p;    /* p is a pointer to char */
char p[];   /* p is an array of chars; p is a string (of chars) */
char *p[];  /* p is an array of pointer to chars; p is an array of strings */
char (*p)[13];    /* p is a pointer to array of 13 chars */
```

# ex5-10, p118
use '*' as command line argument in zsh shell:
https://stackoverflow.com/a/29332008
