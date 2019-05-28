#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>

enum boolean { YES, NO };
// enum evilbool { NO, YES, MAYBE}; // error: redefinition of enumerator 'NO'


void printString(char aString[]);
void intToChar();
void use_strtol();

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
    
  // you *can* declare and init on one line! why not tell me earlier
  char yourkiddingme[] = "yes its true!";
  printf("%s\n", yourkiddingme);
  int meaning = 42;

  intToChar();

  use_strtol();
}

void printString(char aString[]){
  printf("%s\n", aString);
}

void intToChar(){
  int i;
  char c;

  i = 10000000;
  c = 42;
  i = c;
  c = i;
  printf("c=%d\n", c);
  printf("i=%d\n", i);

  i = 256;      // 1 0000 0000
  c = 42;       //   0010 1010
  c = i;        // X 0000 0000  Higher order bit (X) is dropped leaving 0
  i = c;        // 0 0000 0000  c's bits are promoted to int but still 0
  printf("c=%d\n", c);
  printf("i=%d\n", i);
  printf("CHARMAX %d\n", CHAR_MAX);

}

void use_strtol(){
  char *ptr;
  long lfromhex = strtol("oxaf", &ptr, 10);
  printf("oxaf -> %ld\n", lfromhex);
}