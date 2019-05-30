#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned int y);

int main()
{
  //   631
  //   4268421  <- places
  //   1421421  <- handy dandy octal converter
  unsigned x0110101 = 065;
  unsigned y0000110 = 06;
  unsigned r0111001 = 071; //expected 57  
  unsigned rAct = setbits(x0110101, 4, 3, y0000110);
  printf("return=%d, expected=%d\n", r0111001, rAct);
}

unsigned setbits(unsigned x, int p, int n, unsigned int y){
  int maskRight = ~(~0 << n); // 00000111 for n = 3
  int lShift = (p+1-n);
  int yField = (y & maskRight) << lShift; // 000yyy00 for p = 4
  int xField = x & ~(maskRight << lShift);// xxx000xx
  return xField | yField;
}
