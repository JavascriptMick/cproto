#include <stdio.h>

#define NTHCOLUMN 18
#define BUFFERLEN 1000
#define INWORD 1
#define OUTWORD 0
#define TRUE 1
#define FALSE 0

int dumpAndShuffle(char buffer[], int nn, int n);
void initBuffer(char buffer[], int len);
int isWhitespace(char c);

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
      dumpAndShuffle(buffer, n, n);
      n = nn = 0;
    } else {
      if(n > NTHCOLUMN) {
        //wrap
        nn = n = dumpAndShuffle(buffer, nn, n);
        state = INWORD;
        putchar('\n');
      } else
        if(isWhitespace(c)==TRUE){
          if(state==INWORD) {
            state = OUTWORD;
            nn = n-1;
          }
        } else
          state = INWORD;
    }
  }   
}

int dumpAndShuffle(char buffer[], int nn, int n)
{
  int i, ii, c, leading;
  ii = 0;
  leading = TRUE;
  for(i = 0; i < BUFFERLEN; i++) {
    c = buffer[i];
    if(i<nn)
      putchar(c); //dump
    else if(i<n && (isWhitespace(c)==FALSE || leading==FALSE)){
      buffer[ii++] = c; //shuffle
      leading = FALSE;
    }
    buffer[i] = 0; //clear
  }
  return ii;
}

void initBuffer(char buffer[], int len) {
  int i;
  for(i = 0; i < len; ++i)
    buffer[i] = 0;
}

int isWhitespace(char c) {
  if(c == ' ' || c == '\t')
    return TRUE;
  else
    return FALSE;
}

