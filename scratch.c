#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>

enum boolean { YES, NO };
// enum evilbool { NO, YES, MAYBE}; // error: redefinition of enumerator 'NO'


void printString(char aString[]);
void playWithBool();
void declareAndInit();
void intToChar();
void use_strtol();
void use_bitwise();
void playWithIntDivision();
char pchar(int i);

int main()
{
  // putchar('0' + 1);
  printString("1234567890");
  playWithBool();
  declareAndInit();
  intToChar();
  use_strtol();
  use_bitwise();
  playWithIntDivision();
}

void printString(char aString[]){
  printf("%s\n", aString);
}

void playWithBool(){
  int isGood;
  isGood = YES;
  if(isGood==YES)
    printf("Its true, enums work\n");
  else
    printf("enums are rubbish\n");
}

void declareAndInit(){
  // you *can* declare and init on one line! why not tell me earlier
  char yourkiddingme[] = "yes its true!";
  printf("%s\n", yourkiddingme);
  int meaning = 42;
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

void use_bitwise()
{
  //   631
  //   4268421  <- places
  //   1421421  <- handy dandy octal converter
  int b0010010 = 022;
  int b0001010 = 012;
  int b0000010 = b0010010 & b0001010; //= 02 octal/dec. & (AND) MASKS OUT input bits where the mask is 0 
  printf("0010010 & 0001010 = 0000010 %d [2]\n", b0000010);

  int b0011010 = b0010010 | b0001010; //= 32 octal 26dec. | (OR) turns bits on 
  printf("0010010 | 0001010 = 0011010 %d [26]\n", b0011010);

  int b0011000 = b0010010 ^ b0001010; //=030 octal 24 dec. ^ (XOR) gives 1 if difference which is highlighted 
  printf("0010010 ^ 0001010 = 0011000 %d [24]\n", b0011000);

  // ~ (ones complement) flips bits so x = x & ~077 sets the last 6 bits to zero
  // so you could have a bitmask with 1's in the values you want to represent
  // and use & ~MASK to turn the bits in the mask OFF in the lhs
  int b0010000 = b0010010 & ~07; //=020 octal 16 dec.
  printf("0010010 ^ ~07  = 0010000 %d [16]\n", b0010000);
}

void playWithIntDivision(){
  printf("1/2 = %d\n", 1/2);
  printf("2/3 = %d\n", 2/3);
  printf("9/10 = %d\n", 9/10);  // 0.. no rounding up here
  printf("18 %% 10 = %d\n", 18 % 10);
}

char pchar(int i){
  if(i=='\n')
    return 'n';
  else if(i==' ')
    return '_';
  else if(i=='\t')
    return 't';
  else return i;
}