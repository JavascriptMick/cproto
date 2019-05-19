#include <stdio.h>
#define MAXLINE 1000  //max line size
#define SPACES 4
#define INSPACE 0
#define OUTSPACE 1

void printtabs(int nSpaces);

//entab - replace spaces with tabs
int main()
{
  int c, state, countspace;
  state = OUTSPACE;
  countspace = 0;
  while((c = getchar()) != EOF)
    if(c=='\t' || c==' ') {
      if (state == OUTSPACE){
        state = INSPACE;
        countspace = 0;
      }

      if(c=='\t')
        countspace = countspace + SPACES;
      else if (c==' ')
        countspace = countspace + 1;
    } else {
      if (state == INSPACE) {
        //put tabs and spaces to make up countspace
        printtabs(countspace);
        state = OUTSPACE;
        countspace = 0;
      } 
      putchar(c);
    }
}

void printtabs(int nSpaces) {
  while(nSpaces > 0){
    if(nSpaces >= SPACES){
      putchar('\t');
      nSpaces = nSpaces - SPACES;
    } else {
      putchar(' ');
      --nSpaces;
    }
  }
}
      