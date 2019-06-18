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
    int n, i, array[SIZE], getint(int *), r;
    for (n = 0; n < SIZE; n++)
        array[n] = 0;

    for (n = 0; n < SIZE && (r = getint(&array[n])) != EOF && r != 0; n++)
        ;
    
    for (i = 0; i < n; i++)
        printf("%d -> %d\n", i, array[i]);
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
    if (c == '+' || c == '-'){
        c = getch();
        if(!isdigit(c)){
            ungetch(c);
            return 0;
        }
    }
    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');
    *pn *= sign;
    if (c != EOF)
        ungetch(c);
    return c;
}