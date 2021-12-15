/* ex4-4, based on  cha4-3 example */

#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <math.h>   /* for fmod() */

#define MAXOP 100   /* max size of operand or operator */
#define NUMBER '0'  /* signal that a number was found */
#define PRINT 'p'   /* command for printing top of stack */
#define SWAP 's'    /* command for swap top two number in stack */
#define DUPLICATE 'd'   /* command for duplicate top of stack */

int getop(char []);
void push(double);
double pop(void);
void print(void);
void swap(void);
void duplicate(void);

/* reverse Polish calculator */
int main()
{
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        switch (type) {
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
        case PRINT:
            print();
            break;
        case SWAP:
            swap();
            break;
        case DUPLICATE:
            duplicate();
            break;
        default:
            printf("error: unknown command %s\n", s);
            break;
        }
    }
    return 0;
}


#define MAXVAL 100 /* maximum depth of val stack */

int sp = 0;         /* next free stack position */
double val[MAXVAL]; /* value stack */

/* push: push f onto value stack */
void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else
    {
        printf("error: stack empty\n");
        return 0.0;
    }
}

/* print: */
void print(void)
{
    if (sp > 0)
        printf("%g", val[sp - 1]);
    else
        printf("error: stack empty\n");
}

/* swap: */
void swap(void)
{
    double temp;

    if (sp >= 2) {
        temp = val[sp - 1];
        val[sp - 1] = val[sp - 2];
        val[sp - 2] = temp;
    } else
        printf("error: too few numbers in stack\n");

}

/* duplicate: */
void duplicate(void)
{
    if (sp > 0 && sp < MAXVAL) {
        val[sp + 1] = val[sp];
        sp++;
    } else if (sp <= 0)
        printf("error: empty stack, can't duplicate\n");
    else
        printf("error: stack full, can't duplicate\n");
}

/* chapter 4.3, p78 */
#include <ctype.h>

int getch(void);
void ungetch(int);

/* getop: get next operator or numeric operand */
int getop(char s[])
{
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.')
        return c; /* not a number */
    i = 0;
    if (isdigit(c)) /* collect integer part */
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.') /* collect fration part */
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}


#define BUFSIZE 100

char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0;   /* next free position in buf */

int getch(void) /* get a (possible pushed back) character */
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) /* push character back on input */
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}


