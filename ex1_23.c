#include <stdio.h>

#define TRUE 1
#define FALSE 0

// Remove whitespace from a c program including this.
/* and this */
/*
and this
*/
int main()
{
  int c, lc, inBlockComment, inLineComment;
  inBlockComment = FALSE;
  inLineComment = FALSE;
  lc = 0;
  while((c = getchar()) != EOF) {
    if(inBlockComment == FALSE && inLineComment==FALSE){
      if(lc=='/' && c=='/'){
        inLineComment = TRUE;
        c = 0;
      }
      else if(lc=='/' && c=='*'){
        inBlockComment = TRUE;
        c = 0;
      }
      else if(lc != 0)
        putchar(lc);
    } else if(inLineComment == TRUE){
      if(c=='\n')
        inLineComment = FALSE;  //lc will become \n, the return is valid
    } else if(inBlockComment == TRUE){
      if(lc=='*' && c=='/'){
        inBlockComment = FALSE;
        c = 0;
      }
    }
    lc = c;
  }
  return 0;
}
