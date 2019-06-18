#include <stdio.h>
#include <ctype.h>

#include "util.h"

#define SIZE 3
/*
gcc -c util.c (once)
gcc -c ex5_1.c && gcc ex5_1.o util.o
*/


int main()
{
    int n, array[SIZE], getint(int *);
    for (n = 0; n < SIZE && getint(&array[n]) != EOF; n++)
        ;
    
    for (n = 0; n < SIZE; n++)
        printf("%d -> %d\n", n, array[n]);
}

int getint(int *pn)
{
    int c, sign;
    while (isspace(c = getch())) /* skip white space */
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-')
    {
        ungetch(c); /* it's not a number */
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
        c = getch();
    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');
    *pn *= sign;
    if (c != EOF)
        ungetch(c);
    return c;
}