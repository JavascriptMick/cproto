#include <stdio.h>

void lower(char s[]);

int main()
{
  char s[] = "Peter Jordansen";
  printf("%s\n", s);
  lower(s);
  printf("%s\n", s);
}

void lower(char s[]){
  int i = 0;
  char c;
  while((c = s[i]) != '\0')
    s[i++] = (c >= 'A' && c <= 'Z')?c - ('A' - 'a'): c;
}
