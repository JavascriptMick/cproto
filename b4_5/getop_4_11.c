#include <stdio.h>
#include <ctype.h>
#include "calc.h"

/* getop: get next operator or numeric operand */
/*
Exercise 4-11. Modify getop so that it doesn't need 
to use ungetch. Hint: use an internal static variable.
... I think this is what they meant but it is really horrible

cc calc.h getop_4_11.c main.c stack.c
*/
int getop(char s[])
{
  static char buf[100]; /* buffer for ungetch*/
  static int bufp = 0;      /*nextfreepositioninbuf*/

  int i, c, n;
  while ((s[0] = c = (bufp > 0) ? buf[--bufp] : getchar()) == ' ' || c == '\t')
    ;                       /* skip whitespace */
  s[1] = '\0';
  if (!isdigit(c) && c != '.'){
    if(c=='-'){
      if(isdigit(n = (bufp > 0) ? buf[--bufp] : getchar())){ /* 'peek' at the next char */
        i = 0;
        s[++i] = n;
        while (isdigit(s[++i] = c = (bufp > 0) ? buf[--bufp] : getchar()))
          ;
      } else {
        if (bufp < 100)
          buf[bufp++] = n;
        // ungetch(n); /* no good, put it back */
        return c;
      }
    } 
    else
      return c;               /* not a number */
  } else {
    i = 0;
    if (isdigit(c)) /* collect integer part */
      while (isdigit(s[++i] = c = (bufp > 0) ? buf[--bufp] : getchar()))
        ;
  }

  if (c == '.') /* collect fraction part */
    while (isdigit(s[++i] = c = (bufp > 0) ? buf[--bufp] : getchar()))
      ;
  
  s[i] = '\0';

  if (c != EOF)
    if (bufp < 100)
          buf[bufp++] = c;
    // ungetch(c);

  return NUMBER;
}