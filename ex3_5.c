#include <stdio.h>
#include <string.h>
#include <limits.h>

/*
Writethefunctionitob(n,s,b) thatconvertstheintegern 
into a base b character representation in the string s. 
In particular, i tob ( n , s, 16) formats n as a 
hexadecimal integer in s.
*/

#define MAXLEN 50
void itob(int n, char s[], int b);
void reverse(char s[]);
char dtoc(int d);

int main()
{
  char s[MAXLEN];

  itob(INT_MIN, s, 16);
  printf("INT_MIN=%d, s=%s\n", INT_MIN, s);

  itob(INT_MAX, s, 16);
  printf("INT_MAX=%d, s=%s\n", INT_MAX, s);

  itob(0, s, 16);
  printf("0=%d, s=%s\n", 0, s);

  itob(42, s, 16);
  printf("42=%d, s=%s\n", 42, s);

  itob(-99, s, 16);
  printf("-99=%d, s=%s\n", -99, s);
}

void itob(int n, char s[], int b)
{
  int i, sign;
  sign = n;
  i =0;
  do { /* generate digits in reverse order */
    if(sign < 0)
      s[i++] = dtoc(-(n % b));
    else
      s[i++] = dtoc(n % b);
  } while ((n /= b) != 0);
  
  if (sign < 0)
    s[i++] = '-'; 
  s[i] ='\0';
  reverse(s);
}

char dtoc(int d){
  //convert an integer into a char in the range
  //0-9 and a-z
  if(d<10)
    return d + '0';
  else if(d < 35)
    return d - 10 + 'a';
  else
    return '#';
}

void reverse(char s[]){
  int i, j;
  char c;
  for(i = 0, j = strlen(s) - 1; i < j ; ++i, --j){
    c = s[j];
    s[j] = s[i];
    s[i] = c;
  }
}