#include <stdio.h>

#define NTHCOLUMN 18
#define BUFFERLEN 1000
#define INWORD 1
#define OUTWORD 0

void dumpAndShuffleBuffer(char buffer[], int len);
void initBuffer(char buffer[], int len);

int main()
{
  int c, n, nn, state;
  char buffer[BUFFERLEN];
  initBuffer(buffer, BUFFERLEN);
  state = INWORD;
  n = nn = 0;
  while((c = getchar()) != EOF) {
    buffer[n++] = c;
    if(c == '\n') {
      dumpAndShuffleBuffer(buffer, n);
      n = nn = 0;
    } else {
      if(n > NTHCOLUMN) {
        //wrap
        dumpAndShuffleBuffer(buffer, nn);
        putchar('\n');
        n = n - nn;  // todo includes leading whitespace
        nn = n;
        state = INWORD;
      } else
        if(c==' ' || c=='\t'){
          if(state==INWORD) {
            state = OUTWORD;
            nn = n;
          }
        } else
          state = INWORD;
    }
  }   
}

void dumpAndShuffleBuffer(char buffer[], int len)
{
  int i, ii;
  ii = 0;
  for(i = 0; i < BUFFERLEN; i++) {
    if(i<len)
      putchar(buffer[i]); //dump
    else 
      buffer[ii++] = buffer[i]; //shuffle
    buffer[i] = 0; //clear
  }
}

void initBuffer(char buffer[], int len) {
  int i;
  for(i = 0; i < len; ++i)
    buffer[i] = 0;
}

