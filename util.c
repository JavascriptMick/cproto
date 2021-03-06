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
  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;
  if (c=='\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}

#define ALLOCSIZE 10000 /* size of available space */

static char allocbuf[ALLOCSIZE]; /* storage for alloc */
static char *allocp = allocbuf;  /* next free position */
char *alloc(int n)  /* return pointer to n character */
{
  if (allocbuf + ALLOCSIZE - allocp >= n) { /* it fits */
    allocp += n;
    return allocp - n; /* old p */
  }
  else /* not enough room */
    return 0;
}

#define MAXVAL 100  /*maximum depth of val stack*/

int sp = 0;         /* next free stack position */
double val[MAXVAL]; /* value stack */

/* push: push f onto value stack*/
void push(double f)
{
  if (sp < MAXVAL)
    val[sp++] = f;
  else
    printf("error: stack full, can't push %g\n", f);
}
/* pop: pop and return top value from stack*/
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