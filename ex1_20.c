#include <stdio.h>
#define MAXLINE 1000  //max line size
#define SPACES 4

void printchars(char c, int nTimes);

//replace tabs in the input with a fixed number of spaces
int main()
{
  int c;
  while((c = getchar()) != EOF)
    if(c=='\t')
      printchars(' ', SPACES);
    else
      putchar(c);
  
}

void printchars(char c, int nTimes){
  int i;
  for(i = 0; i<nTimes; ++i)
    putchar(c);
}
      