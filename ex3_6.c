#include <stdio.h>
#include <string.h>
#include <limits.h>

/*
Write a version of i toa that accepts three arguments 
instead of two. The third argument is a minimum field 
width; the converted number must be padded with blanks 
on the left if necessary to make it wide enough
*/


#define MAXLEN 50
void itoa(int n, char s[], int w);
void reverse(char s[]);

int main()
{
  char s[MAXLEN];

  itoa(INT_MIN, s, 15);
  printf("INT_MIN=%d \t s=%s\n", INT_MIN, s);

  itoa(INT_MAX, s, 15);
  printf("INT_MAX=%d \t s=%s\n", INT_MAX, s);

  itoa(0, s, 15);
  printf("0=%d \t\t\t s=%s\n", 0, s);

  itoa(42, s, 15);
  printf("42=%d \t\t\t s=%s\n", 42, s);

  itoa(-99, s, 15);
  printf("-99=%d \t\t s=%s\n", -99, s);
}

void itoa(int n, char s[], int w)
{
  int i, sign, j;
  sign = n;
  i =0;
  do { /* generate digits in reverse order */
    if(sign < 0)
      s[i++] =-(n % 10) + '0';
    else
      s[i++] = n % 10 + '0';
  } while ((n /= 10) != 0);

  if (sign < 0)
    s[i++] = '-'; 

  while(i < w)
    s[i++] = ' ';
  
  s[i] ='\0';
  reverse(s);
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