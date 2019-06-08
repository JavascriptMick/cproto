#include <stdio.h>
#include <string.h>

void reverse(char s[]);

int main()
{
  char odd[] = "hello dolly";
  reverse(odd);
  printf("%s\n", odd);

  char even[] = "Shazam";
  reverse(even);
  printf("%s\n", even);
}

void reverse(char s[]){
  int i, j;
  char c;
  for(i = 0, j = strlen(s) - 1; i < j ; ++i, --j){
    c = s[j];
    s[j] = s[i];
    s[i] = c;
  }
}