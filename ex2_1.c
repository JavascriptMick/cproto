#include <stdio.h>
#include <limits.h>
#include <float.h>

void printBits(long i);

int main()
{
  
  /*
  Write a program to determine the ranges of char, short, int,
  and long variables, both signed and unsigned, by printing appropriate values from standard headers and by direct computation. Harder if you com- pute them: determine the ranges of the various floating-point types.
  */
  printf("Basic Datatype limits\n");
  printf("\nchar %d -> %d\n", CHAR_MIN, CHAR_MAX);
  printf("CHAR_MAX"); printBits(CHAR_MAX);
  printf("\nshort %d -> %d\n", SHRT_MIN, SHRT_MAX);
  printf("SHRT_MAX"); printBits(SHRT_MAX);
  printf("\nint %d -> %d\n", INT_MIN, INT_MAX);
  printf("INT_MAX"); printBits(INT_MAX);
  printf("\nlong %ld -> %ld\n", LONG_MIN, LONG_MAX);
  printf("LONG_MAX"); printBits(LONG_MAX);
  
  printf("\nunsigned char -> %d\n", UCHAR_MAX);
  printf("UCHAR_MAX"); printBits(UCHAR_MAX);
  printf("\nunsigned short -> %d\n", USHRT_MAX);
  printf("USHRT_MAX"); printBits(USHRT_MAX);
  printf("\nunsigned int -> %d\n", UINT_MAX);
  printf("UINT_MAX"); printBits(UINT_MAX);
  printf("\nunsigned long -> %ld\n", ULONG_MAX);
  printf("ULONG_MAX"); printBits(ULONG_MAX);

  // boundary behaviour
  printf("Boundary Behaviour\n");
  int i; i = INT_MIN;
  printf("i(INT_MIN)=%d\n", i);
  i = i - 1;
  printf("i(-1)=%d\n", i);
  i = INT_MAX;
  printf("i(INT_MAX)=%d\n", i);
  i = i + 1;
  printf("i(+1)=%d\n", i);

}

void printBits(long i){
  unsigned long a, pa;
  int b;
  if(i < 2)
    printf(" is too low to calculate");
  else {
    a = 1;
    for(b=1; b < INT_MAX; ++b){
      pa = a;
      a = a * 2;
      if(a==0) {
        printf(" multiplication tapped out at %d bits with a value of %ld\n", b-1, pa);
        return;
      }
      if(a == i) {
        printf(" is a whole binary number with %d bits\n", b);
        return;
      }
      if(a > i){
        printf(" falls between whole binary numbers between %d and %d bits\n", b, b + 1);
        return;
      }
    }
    printf(" loop tapped out at %d bits with a value of %ld\n", b, a);

  }
}