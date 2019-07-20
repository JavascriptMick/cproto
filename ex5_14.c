#include <stdio.h> 
#include <string.h>
#include "util.h"

#define MAXLINES 5000 /* max #lines to be sorted */
#define MAXLEN 1000 /* max length of any input line*/

char *lineptr[MAXLINES]; /*pointers to text lines*/

int readlines(char *lineptr[], int nlines); 
void writelines(char *lineptr[], int nlines);
void qqsort(void *lineptr[], int left, int right, int (*comp)(void *, void *), int reverse);
int numcmp(char *, char *);

/* sort input lines */ 
int main(int argc, char *argv[])
{
  int nlines; /* number of input lines read */
  int numeric = 0; /* 1 if numeric sort */
  int reverse = 0;
  while(--argc > 0){
    if (strcmp(*++argv, "-n") == 0)
      numeric = 1;
    if (strcmp(*argv, "-r") == 0)
      reverse = 1;
  }

  printf("numeric %d\n", numeric);
  printf("reverse %d\n", reverse);

  if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
    qqsort((void **) lineptr, 0, nlines-1,
      (int (*)(void*,void*))(numeric ? numcmp : strcmp),
      reverse); /* note the cast to an anonymous function that takes 2 pointer arguments */
    writelines(lineptr, nlines);
    return 0;
  } else {
    printf("input too big to sort\n"); 
    return 1;
  } 
}

/*qqsort: sortv[left]•..v[right]into increasing order*/ 
void qqsort(void *v[], int left, int right, int (*comp)(void *, void *), int reverse)
{
  int i, last;
  void swap(void *v[], int, int);
  if(left >= right) /*do nothing if array contains */ 
    return;         /* fewer than two elements */
  swap(v, left, (left + right)/2);
  last = left;
  for (i = left+1; i <= right; i++)
    if(reverse == 0){
      if ((*comp)(v[i], v[left]) < 0)
        swap(v, ++last, i);
    } else {
      if ((*comp)(v[i], v[left]) >= 0)
        swap(v, ++last, i);
    }

  swap(v, left, last);
  qqsort(v, left, last-1, comp, reverse);
  qqsort(v, last+1, right, comp, reverse);
}

#include <stdlib.h>
/* numcmp:compare s1 and s2 numerically */
int numcmp(char *s1, char *s2)
{
  double v1, v2;

  v1 = atof(s1); 
  v2 = atof(s2);
  if (v1 < v2)
    return -1; 
  else if (v1 > v2)
    return 1; 
  else
    return 0;
}

void swap(void *v[], int i, int j){
  void *temp;
  temp =v[i];
  v[i] = v[j];
  v[j] =temp;  
}

/* readlines: readinputline */
int readlines(char *lineptr[], int maxlines)
{
  int len, nlines;
  char *p, line[MAXLEN];
  nlines = 0;
  while ((len = getnextline(line, MAXLEN)) > 0)
    if (nlines >= maxlines || (p = alloc(len)) == NULL)
      return -1;
    else
    {
      line[len - 1] = '\0'; /*delete new line*/
      strcpy(p, line);
      lineptr[nlines++] = p;
    }
  return nlines;
}

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines){
  while (nlines-- > 0)
    printf("%s\n", *lineptr++);
}