#include <stdio.h>
#define MAXLINE 1000  //max line size

int getnextline(char line[], int maxline);  //apparently there is a getline in stdio.h so I can't use that name

//print input lines longer than 80 chars
int main()
{
  int len;    // current line length
  char line[MAXLINE];     // current input line
  
  len = 0;
  while ((len = getnextline(line, MAXLINE)) > 0) {
    if(len > 80)
      printf("%s\n", line);
  }
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
