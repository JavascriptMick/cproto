#include <stdio.h>
#define MAXLENGTH 100
/*
Write a function expand (s 1,s2) that expands
shorthand nota- tions like a - z in the
string s 1 into the equivalent complete list
abc ... xyz in s2. Allow for letters of either
case and digits, and be prepared to handle
cases like a-b-c and a-zO-9 and -a-z.
Arrange that a leading or trailing -
is taken literally.
*/

void expand(char s1[], char s2[]);
void testExpand(char s1[]);

int main()
{
  testExpand("Hex uses the characters 0-9 and a-f.");
  testExpand("a-b-c");
  testExpand("a-b-g");
  testExpand("a--z");
  testExpand("z-a");
  testExpand("a-d-b");
  testExpand("-first point");
  testExpand("-emphasis-");
}

void expand(char s1[], char s2[]){
  int i, j, expanding;
  char c, ce, cs;
  i = expanding = 0;
  for(i=0, j=0; (c=s1[i]) != '\0'; ++i){
    if(expanding){
      if(c!='-'){
        if(c >= cs)
          for(ce = cs + 1; ce<=c; ++ce)
            s2[j++] = ce;
        else
          for(ce = cs - 1; ce>=c; --ce)
            s2[j++] = ce;    
        cs = c;
        expanding = 0;
      }
    } else {
      if(c=='-' && cs > 0)
        expanding = 1;
      else
        s2[j++] = cs = c;
    }
  }
  if(expanding)
    s2[j++] = '-';

  s2[j] = '\0';
}

void testExpand(char s1[]){
  char s2[MAXLENGTH];
  expand(s1, s2);
  printf("%s\n%s\n\n", s1, s2);
}