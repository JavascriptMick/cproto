#include <stdio.h>
#include "util.h"
#define BUFSIZE 100

char buf[BUFSIZE]; /* buffer for ungetch*/
int bufp = 0;      /*nextfreepositioninbuf*/

int getch(void)    /* get a (possibly pushedback) character*/
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

int getnextline(char *s, int lim) {
  int c, i;
  for(i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
    s[i] = c;
  if (c=='\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}