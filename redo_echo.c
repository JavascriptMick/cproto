#include <stdio.h>

main()
{
  int c, check;
  c = getchar();
  check = (c != EOF);
  printf("the answer is %d \n", check);
  printf("the magic value of EOF is %d\n", EOF);
}
