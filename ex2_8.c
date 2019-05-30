#include <stdio.h>

unsigned rightrot(unsigned x, int n);
void printbits(unsigned x);

int main()
{
  //        631
  //        4268421  <- places
  //        1421421  <- handy dandy octal converter
  unsigned x0110101 = 065; // 53 dec
  printbits(x0110101);
  unsigned rAct = rightrot(x0110101, 3);
  printbits(rAct);
}

unsigned rightrot(unsigned x, int n){
  int i;
  for(i=0; i<n; i++)
    x = (x << 31) | (x >> 1);
  return x;
}

void printbits(unsigned x){
  unsigned char bits[32];
  for(int i=0; i < 32; ++i)
    bits[i] = '0' + ((x << i) >> 31);
  printf("%s (oct:0%o, dec:%u)\n", bits, x, x);
}
