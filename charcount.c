#include <stdio.h>

//count characters
int main(int argc, char const *argv[])
{
  long nc;

  nc = 0;
  while(getchar() != EOF)
    ++nc;
  printf("here...%ld\n", nc);
  
  return 0;
}
