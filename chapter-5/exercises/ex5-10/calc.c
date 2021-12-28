#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

void push(int);
int pop(void);

/* calc: reverse Polish caculator on a list of string */
int calc(int argc, char *argv[])
{
    int c, op2;

    while (*++argv) {
        // printf("curr: %s\n", *argv);
        if (isdigit(**argv)) {
            push(atoi(*argv));
        } else {
            switch(**argv) {
            case '+':
                push(pop() + pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '*':
                push(pop() * pop());
                break;
            case '/':
                op2 = pop();
                push(pop() / op2);
                break;
            default:
                printf("error: unknow command %s\n", *argv);
                break;
            }
        }
    }
    /* TODO: error handling */
    return pop();
}