#include <stdio.h>
#include <stdlib.h> /* for atof() */

#define MAXOP 100  /* max size of operand or operator */
#define NUMBER '0'

int getop(char []);
void ungets(char []);
void push(double);
double pop(void);

/* reverse Polish calculator; use command line */
int main()
{
    char s[MAXOP];
    double op2;

    while (--argc > 0) {
        ungets(" ");    /* push end of argument */
        ungets(*++argv);    /* push argment */
        switch (getop(s)) {
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
        case '\n':
            printf("\t%.8g\n", pop());
            break;
        default:
            printf("error: unknown command %s\n", s);
            argc = 1;
            break;
        }
    }
    printf("\t%.8g\n", pop());
    return 0;
}