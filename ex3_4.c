#include <stdio.h>
#include <string.h>
#include <limits.h>

/*
In a two's complement number representation, 
our version of i toa does not handle the largest 
negative number, that is, the value of n equal to 
-(2 ^ (wordsize-l)). Explain why not. Modify it to print 
that value correctly,
regardless of the machine on which it runs.
*/

/*
The original implementation attempted to negate n
with n = -n
IN twos complement notation, negation of the largest negative
number results in the same number!  so the 'negated' number
was still negative and the logic of the function broke down.

Note 1) Negation involves
first calculating the ones complement (flipping the bits)
then adding 1:-

Note 2) With 4 bits, the largest negative number is
-8 (1000) but there is no way to denote +8... 
the max positive number you can denote is +7 (0111)

As this is very strange, to demonstrate (with 4 bits):-

Bin   | Decimal
1000  |  -8
0111  |  Ones complement
0001  | + 1 this produces a cascade of 'cary ones' from right to left resulting in...
1000  !  = ...... -8 Again!!
*/

#define MAXLEN 50
void itoa(int n, char s[]);
void reverse(char s[]);

int main()
{
  char s[MAXLEN];

  itoa(INT_MIN, s);
  printf("INT_MIN=%d, s=%s\n", INT_MIN, s);

  itoa(INT_MAX, s);
  printf("INT_MAX=%d, s=%s\n", INT_MAX, s);

  itoa(0, s);
  printf("0=%d, s=%s\n", 0, s);

  itoa(42, s);
  printf("42=%d, s=%s\n", 42, s);

  itoa(-99, s);
  printf("-99=%d, s=%s\n", -99, s);
}

/*
This implementation avoids negating the 'big' number
and instead negates the mod result to index into the 
character set.  It is still necessary to save off the sign
because at loop exit, n is = 0 and the sign information
is lost.
*/
void itoa(int n, char s[])
{
  int i, sign;
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