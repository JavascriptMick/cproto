#include <stdio.h>

/*
In a two's complement number system, 
x &.= (x-1) deletes the rightmost l-bit in x.
Explain why. Use this observation to write 
a faster version of bitcount.

x &= (x-1)
x = x & (x-1)
x = x MASKED WITH xxxxxxx0 (if x is an unsigned char)
because the mask has a 1 everywhere x has a 1
(except for the last digit), the result is 
x with the rightmost bit set to 0.

*/

int bitcountSlow(unsigned x);
int bitcountFast(unsigned x);
void printbits(unsigned x);

int main()
{
  unsigned x = 0177;  // should have 7 bits
  printbits(x);
  printf("slow %d\n", bitcountSlow(x));
  printf("fast %d\n", bitcountFast(x));
}

int bitcountSlow(unsigned x){
  int b;
  for(b = 0; x != 0; x >>= 1)
    if (x & 01)
      b++;
  return b;
}

int bitcountFast(unsigned x){
  int b;
  for(b = 0; x != 0; x >>= 1)
    b += x - (x & (x-1));
  return b;
}

void printbits(unsigned x){
  unsigned char bits[32];
  for(int i=0; i < 32; ++i)
    bits[i] = '0' + ((x << i) >> 31);
  printf("%s (oct:0%o, dec:%u)\n", bits, x, x);
}