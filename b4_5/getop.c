#include <stdio.h>
#include <ctype.h>
#include "calc.h"

/* getop: get next operator or numeric operand */
int getop(char s[])
{
  int i, c, n;
  while ((s[0] = c = getch()) == ' ' || c == '\t')
    ;                       /* skip whitespace */
  s[1] = '\0';
  if (!isdigit(c) && c != '.'){
    if(c=='-'){
      if(isdigit(n = getch())){ /* 'peek' at the next char */
        i = 0;
        s[++i] = n;
        while (isdigit(s[++i] = c = getch()))
          ;
      } else {
        ungetch(n); /* no good, put it back */
        return c;
      }
    } 
    else
      return c;               /* not a number */
  } else {
    i = 0;
    if (isdigit(c)) /* collect integer part */
      while (isdigit(s[++i] = c = getch()))
        ;
  }

  if (c == '.') /* collect fraction part */
    while (isdigit(s[++i] = c = getch()))
      ;
  
  s[i] = '\0';

  if (c != EOF)
    ungetch(c);

  return NUMBER;
}