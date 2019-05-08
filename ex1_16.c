#include <stdio.h>
#include <limits.h>
#define MAXLINE 1000  //max line size
#define IN 1          // your in a line, start has real data
#define OUT 0         //your not in a line, start has none

int getnextline(char line[], int maxline);  //apparently there is a getline in stdio.h so I can't use that name
void copy(char to[], char from[]);

//print longest input line
int main()
{
  int chunk;  //current chunk length
  int len;    // current line length
  int max;    //max line length seen so far
  int state;
  char line[MAXLINE];     // current input line
  char longest[MAXLINE];  // longest line saved here
  char start[MAXLINE];    // start of the current line

  max = len = 0;
  state = OUT;
  while ((chunk = getnextline(line, MAXLINE)) > 0) {
    len = len + chunk;
    if(line[chunk-1] == '\n'){
      if(len > max) {
        max = len;
        if(state == IN)
          copy(longest, start);
        else
          copy(longest, line);
      }
      len = 0;
      state = OUT;
    } else {
      if(state == OUT){
        copy(start, line);
        state = IN;
      }
    }
  }

  if(max > MAXLINE) //there was a line
    printf("%d:%s...[cont]\n", max, longest);
  else if(max > 0)
    printf("%d:%s\n", max, longest);
  return 0;
}

// not sure why we would use different names from the function prototype?
int getnextline(char s[], int lim) {
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

void copy(char to[], char from[]) {
  int i;

  i = 0;
  while ((to[i] = from[i]) != '\0')
    ++i;
}
