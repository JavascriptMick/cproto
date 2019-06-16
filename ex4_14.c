#include <stdio.h>

#define swap(t, x, y) t temp = y; y = x, x = temp;

int main()
{
  int a = 1;
  int b = 2;
  swap(int, a, b)
  printf("a=%d, b=%d\n", a, b);
}