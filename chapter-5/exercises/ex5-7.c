#include <stdio.h>
#include <string.h>

#define MAXLINES 5000  /* max #lines to be sorted */
#define ALLOCSIZE 10000 /* max sotrage of lines */

char *lineptr[MAXLINES];    /* pointers to text lines */

int readlines(char *lineptr[], int nlines, char *buf, int bufsize);
void writelines(char *lineptr[], int nlines);

void qsort(char *lineptr[], int left, int right);

/* sort input lines */
int main()
{
    int nlines; /* number of input lines read */
    char allocbuf[ALLOCSIZE];

    if ((nlines = readlines(lineptr, MAXLINES, allocbuf, ALLOCSIZE)) >= 0) {
        qsort(lineptr, 0, nlines - 1);
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("error: input too big to sort\n");
        return 1;
    }
}

#define MAXLEN 1000 /* max length of any input line */
int my_getline(char *, int);
char *alloc(int);

/* readlines: read input lines */
int readlines(char *lineptr[], int maxlines, char *buf, int bufsize)
{
    int len, nlines;
    char *bbuf;    /* beginning of buf */

    bbuf = buf;
    nlines = 0;
    while ((len = my_getline(buf, MAXLEN)) > 1)    /* not empty line */
        if (nlines >= maxlines || (buf - bbuf) >= bufsize)
            return -1;
        else {
            buf[len - 1] = '\0';   /* delete newline */
            lineptr[nlines++] = buf;
            buf += len; /* point to next vacant position */
        }
    return nlines;
}

/* writelines: wirte output lines */
void writelines(char *lineptr[], int nlines)
{
    int i;

    for (i = 0;i < nlines; i++)
        printf("%s\n", lineptr[i]);
}

/* qsort: sort v[left]...v[right] into increasing order */
void qsort(char *v[], int left, int right)
{
    int i, last;
    void swap(char *v[], int i, int j);

    if (left >= right)  /* do nothing if array contains */
        return; /* fewer than two elements */
    swap(v, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; i++)
        if (strcmp(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);
    qsort(v, left, last - 1);
    qsort(v, last + 1, right);
}

/* swap: interchange v[i] and v[j] */
void swap(char *v[], int i, int j)
{
    char *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

/* chapter 4.1 */
#include <stdio.h>

/* my_getline: get line into s, return length */
int my_getline(char s[], int lim)
{
    int c, i;

    i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}