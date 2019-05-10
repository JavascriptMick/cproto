#include <stdio.h>
#define MAXLINE 1000  //max line size

int getnextlineNoTrailingWhitespace(char line[], int maxline);  //apparently there is a getline in stdio.h so I can't use that name
void copy(char to[], char from[], int lastIndex);

//very ugly impl of remove trailing whitespace and blank lines
int main()
{
  int len;    // current line length
  char line[MAXLINE];     // current input line
  
  len = 0;
  while ((len = getnextlineNoTrailingWhitespace(line, MAXLINE)) > 0) {
    if(len > 1)
      printf("%s", line);
  }
  return 0;
}

// not sure why we would use different names from the function prototype?
int getnextlineNoTrailingWhitespace(char s[], int lim) {
  int c, i, non_white, outlen;
  char running[MAXLINE];

  non_white = -1;
  for(i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i) {
    running[i] = c;
    if (c != '\t' && c != ' ')
      non_white = i;
  }

  if(non_white >= 0){
    copy(s, running, non_white + 1);
    outlen = non_white + 1;
  } else {
    copy(s, running, i);
    outlen = i;
  }

  //put in the return
  if (c=='\n') {
    s[outlen] = c;
    ++outlen;
  }
  s[outlen] = '\0';
  return outlen;
}

void copy(char to[], char from[], int lastIndex) {
  int i;

  i = 0;
  while (i <= lastIndex && (to[i] = from[i]) != '\0')
    ++i;
}