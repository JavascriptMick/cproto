#include <stdio.h>

unsigned invert(unsigned x, int p, int n);

int main()
{
  //        631
  //        4268421  <- places
  //        1421421  <- handy dandy octal converter
  unsigned x0110101 = 065;
  unsigned r0101001 = 051; //expected 57  
  unsigned rAct = invert(x0110101, 4, 3);
  printf("return=%d, expected=%d\n", r0101001, rAct);
}

unsigned invert(unsigned x, int p, int n){
  int lShift = (p+1-n);
  int mask = ~(~0 << n) << lShift; // 00011100 for n = 3 and p = 4
  return (x & ~mask) | (~x & mask);
}
