#include <stdio.h>
#include <ctype.h>
#include <stdlib.h> /* for atof() */

#include "util.h"

#define SIZE 3
#define MAXFLOATSIZE 100
/*
gcc -c util.c (once)
gcc -c ex5_2.c && gcc ex5_2.o util.o
*/


int main()
{
    int n, i, r, getfloat(float *);
    float array[SIZE];
    for (n = 0; n < SIZE; n++)
        array[n] = 0.0f;

    for (n = 0; n < SIZE && (r = getfloat(&array[n])) != EOF && r != 0; n++)
        ;
    
    for (i = 0; i < n; i++)
        printf("%d -> %f\n", i, array[i]);
}

int getfloat(float *pn) {
    int c, i, pcount;
    char s[MAXFLOATSIZE];
    while(isspace(c = getch()))
        ;
    if(!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.'){
        ungetch(c);
        return 0;
    }
    pcount = i = 0;
    if(c == '+' || c == '-'){
        s[i++] = c;
        c = getch();
        if(!isdigit(c) && c != '.'){
            ungetch(c);
            return 0;
        } else if(c=='.'){ /* -.4 */
            pcount = 1;
            s[i++] = c;
            c = getch();
        }
    }
    for(; (isdigit(c) || (c == '.' && !pcount++)) && i < MAXFLOATSIZE; c = getch())
        s[i++] = c;
    s[i] = '\0';
    *pn = atof(s);
    if(c != EOF)
        ungetch(c);
    return c;
}
