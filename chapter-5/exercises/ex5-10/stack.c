#include <stdio.h>

#define MAXVAL 100 /* maximum depth of val stack */

int sp = 0;         /* next free stack position */
int val[MAXVAL]; /* value stack */

/* push: push f onto value stack */
void push(int i)
{
    if (sp < MAXVAL)
        val[sp++] = i;
    else
        printf("error: stack full, can't push %d\n", i);
}

/* pop: pop and return top value from stack */
int pop(void)
{
    if (sp > 0)
        return val[--sp];
    else
    {
        printf("error: stack empty\n");
        return 0;
    }
}