#include <stdio.h>
#include <limits.h>
#include <float.h>

void printBits(unsigned long i);

int main()
{
  
  /*
  Write a program to determine the ranges of char, short, int,
  and long variables, both signed and unsigned, by printing appropriate values from standard headers and by direct computation. Harder if you com- pute them: determine the ranges of the various floating-point types.
  */
  printf("Basic Datatype limits (understanding 2s complement)\n");
  printf("\nchar %d -> %d\n", CHAR_MIN, CHAR_MAX);
  printf("CHAR_MAX"); printBits(CHAR_MAX);
  printf("\nshort %d -> %d\n", SHRT_MIN, SHRT_MAX);
  printf("SHRT_MAX"); printBits(SHRT_MAX);
  printf("\nint %d -> %d\n", INT_MIN, INT_MAX);
  printf("INT_MAX"); printBits(INT_MAX);
  printf("\nlong %ld -> %ld\n", LONG_MIN, LONG_MAX);
  printf("LONG_MAX"); printBits(LONG_MAX);
  
  printf("\nunsigned char -> %u\n", UCHAR_MAX);
  printf("UCHAR_MAX"); printBits(UCHAR_MAX);
  printf("\nunsigned short -> %u\n", USHRT_MAX);
  printf("USHRT_MAX"); printBits(USHRT_MAX);
  printf("\nunsigned int -> %u\n", UINT_MAX);
  printf("UINT_MAX"); printBits(UINT_MAX);
  printf("\nunsigned long -> %lu\n", ULONG_MAX);
  printf("ULONG_MAX"); printBits(ULONG_MAX);

  // boundary behaviour
  printf("\nInteger Boundary Behaviour\n");
  int i; i = INT_MIN;
  printf("i(INT_MIN)=%d\n", i);
  i = i - 1;
  printf("i(-1)=%d\n", i);
  i = INT_MAX;
  printf("i(INT_MAX)=%d\n", i);
  i = i + 1;
  printf("i(+1)=%d\n", i);

  printf("\nfloat %f -> %f\n", FLT_MIN, FLT_MAX);
  printf("\ndouble %f -> %f\n", DBL_MIN, DBL_MAX);
  printf("\nlong double %Lf -> %Lf\n", LDBL_MIN, LDBL_MAX);
}

void printBits(unsigned long i){
  unsigned long a;
  int b;
  if(i < 2)
    printf(" is too low to calculate\n");
  else {
    a = 1;
    for(b=1; b < INT_MAX; ++b){
      a = a * 2;
      if(a==0) {
        printf(" multiplication tapped out at %d bits \n", b);
        return;
      }
      if(a-1 == i) {
        printf(" uses %d bits\n", b);
        return;
      }
    }
    printf(" loop tapped out at %d bits with a value of %ld\n", b, a);
  }
}
