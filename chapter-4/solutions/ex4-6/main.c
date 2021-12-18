#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include "calc.h"

#define MAXOP 100  /* max size of operand or operator */

/* reverse Polish calculator */
int main()
{
    int i, type, var = 0;   /* initial var shall not be valid */ 
    double op2, varialbles[26], v;
    char s[MAXOP];


    for (i = 0; i < 26; i++)
        varialbles[i] = 0.0;
    while ((type = getop(s)) != EOF)
    {
        switch (type)
        {
        case NUMBER:
            push(atof(s));
            break;
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '/':
            op2 = pop();
            if (op2 != 0.0)
                push(pop() / op2);
            else
                printf("error: zero divisor\n");
            break;
        case '=':
            pop();  /* revert push via varaible name before '=' */
            if (var >= 'A' && var <= 'Z')
                push(varialbles[var - 'A'] = pop());
            else
                printf("error: no variable name");
            break;
        case '\n':
            v = pop();
            printf("\t%.8g\n", v);
            break;
        default:
            if (type >= 'A' && type <= 'Z')
                push(varialbles[type - 'A']);
            else if (type == 'v')
                push(v);
            else
                printf("error: unknown command %s\n", s);
            break;
        }
        var = type;
    }
    return 0;
}