#include <stdio.h>

#define IN  1 // inside a word
#define OUT 0 // outside a word

// count lines, words and chars in the input
int main(int argc, char const *argv[])
{
  int c, nl, nw, nc, state;
  nl = nw = nc = 0;

  state = OUT;

  while((c = getchar()) != EOF) {
    ++nc;
    if(c == '\n')
      ++nl;
    if(c == ' ' || c == '\n' || c == '\t')
      state = OUT;
    else if (state == OUT) {
      state = IN;
      ++nw;
    }
  }
  printf("%d %d %d\n", nl, nw, nc);
  
}

