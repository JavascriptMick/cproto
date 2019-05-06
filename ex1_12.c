#include <stdio.h>

// print input one word per line
int main()
{
  int c;
  while((c = getchar()) != EOF) {
    if(c == ' ' || c == '\n' || c == '\t')
      putchar('\n');
    else
      putchar(c);
  }  
}

