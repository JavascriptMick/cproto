#include <stdio.h>

main()
{
  int check;
  int cc;
  cc = 0;
  while(1) {
    check = (getchar() != EOF);
    putchar(124);
    cc = cc + 1;
  }
}
