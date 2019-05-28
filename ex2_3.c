#include <stdio.h>

/*
convert hex string to decimal
0-9, a-f, A-F
0X and 0x prefix is optional
*/
long htoi(char s[]);

int main()
{
  //should work
  printf("0xa -> %ld\n", htoi("0xa"));
  printf("0Xaf -> %ld\n", htoi("0Xaf"));
  printf("0x22 -> %ld\n", htoi("0x22"));
  printf("12345 -> %ld\n", htoi("12345"));

  //should fail
  printf("zx12345 -> %ld\n", htoi("zx12345"));
  printf("0XX -> %ld\n", htoi("0XX"));
  printf("0Xafz -> %ld\n", htoi("0Xafz"));
}

long htoi(char s[]){
  int i, offset, multiplier;
  char c, digitvalue;
  long acc = 0;
  if(s[0]=='0' && (s[1]=='x' || s[1]=='X'))  // precedence of && is higher than ||
    offset = 2;
  else
    offset = 0;
  
  //walk forward and count the real characters
  for(i = offset; (c = s[i])!='\0'; ++i);
  
  //walk backward and accumulate the result
  multiplier = 1;
  for(i = i - 1;i >= offset; --i){
    c = s[i];
    if (c >= '0' && c <= '9')
      digitvalue = c - '0';
    else if (c >= 'a' && c <= 'f')
      digitvalue = c - 'a' + 10;
    else if (c >= 'A' && c <= 'F')
      digitvalue = c - 'A' + 10;
    else {
      printf("%s is not a valid hex value\n", s);
      return 0;
    }
    acc = acc + (digitvalue * multiplier);
    multiplier = multiplier * 16;
  }
  return acc;
}