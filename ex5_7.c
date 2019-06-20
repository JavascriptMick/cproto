#include <stdio.h>
#include <string.h>
#include "util.h"

#define MAXLINES 5000 /* max Ilines to be sorted */

char *lineptr[MAXLINES]; /* pointers to text lines */

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void qsort(char *lineptr[], int left, int right);

/*
gcc -c util.c (once)
gcc -c ex5_7.c && gcc ex5_7.o util.o
*/

/* sort input lines */
int main()
{
  int nlines; /* number of input lines read */
  if ((nlines = readlines(lineptr, MAXLINES)) >= 0)
  {
    qsort(lineptr, 0, nlines - 1);
    writelines(lineptr, nlines);
    return 0;
  }
  else
  {
    printf("error: input too big to sort\n");
    return 1;
  }
}
