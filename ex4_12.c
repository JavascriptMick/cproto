#include <stdio.h>
#include <string.h>
#include <limits.h>

/*
Exercise 4-12. Adapt the ideas of printd to write a recursive version of i toa; that is, convert an integer into a string by calling a recursive routine. 0
*/

#define MAXLEN 50
void itoa(int n, char s[]);
int _itoa(int n, char s[], int sign);

int main()
{
  char s[MAXLEN];

  itoa(INT_MIN, s);
  printf("INT_MIN=%d \t s=%s\n", INT_MIN, s);

  itoa(INT_MAX, s);
  printf("INT_MAX=%d \t s=%s\n", INT_MAX, s);

  itoa(0, s);
  printf("0=%d \t\t\t s=%s\n", 0, s);

  itoa(42, s);
  printf("42=%d \t\t\t s=%s\n", 42, s);

  itoa(-99, s);
  printf("-99=%d \t\t s=%s\n", -99, s);
}

void itoa(int n, char s[]){
  int sign, p;
  sign = n; //preserve sign
  p = _itoa(n, s, sign);
  s[p] ='\0';
}

int _itoa(int n, char s[], int sign)
{
  char c;
  int p;
  if(sign < 0)
    c =-(n % 10) + '0';
  else
    c = n % 10 + '0';
      
  if (n / 10 != 0){
    p = _itoa(n/10, s, sign);
    s[p] = c;
    return p + 1;
  }
  else
    if (sign < 0){
      s[0] = '-';
      s[1] = c;
      return 2;
    } else {
      s[0] = c;
      return 1;
    }
}
