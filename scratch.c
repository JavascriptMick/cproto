#include <stdio.h>
#include <string.h>
enum boolean { YES, NO };
// enum evilbool { NO, YES, MAYBE}; // error: redefinition of enumerator 'NO'


void printString(char aString[]);

int main()
{
  // putchar('0' + 1);
  printString("1234567890");
  int isGood;
  isGood = YES;
  if(isGood==YES)
    printf("Its true, enums work\n");
  else
    printf("enums are rubbish\n");
}

void printString(char aString[]){
  printf("%s\n", aString);
}