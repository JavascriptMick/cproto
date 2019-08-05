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
void playWithArrayPointers();
void playWithFunctionPointers();
void playWithComplexDeclarations();
void playWithUnions();

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
  playWithArrayPointers();
  playWithFunctionPointers();
  playWithComplexDeclarations();
  playWithUnions();
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

void playWithArrayPointers(){
  char _[] = "9876543210";
  char s[] = "abcdefg";
  char *c = &s[3];
  printf("s=%s (contents of s)\n", s);
  printf("s=%p (the address of s)\n", s);
  printf("*(s+4)=%c\n", *(s+4));
  printf("*c=&s[3]=%c\n", *c);
  printf("*(c-1)=%c\n", *(c-1));
  
  /* Illegal?? */
  printf("*(c-5)=%c(%d)\n", *(c-5), *(c-5)); // no error here.. wierd
  
  /* Illegal */
  // char *f = _ + s; //- invalid operands to binary expression ('char *' and 'char *')
}

int add(int i, int j){
  return i + j;
}
int sub(int i, int j){
  return i - j;
}
int pmult(int *i, int *j){
  return *i * *j; //lol.. so many *
}

void playWithFunctionPointers(){
  printf("Mathematical Magic\n");

  // Pointer to a function that takes 2 ints and returns an int
  int (*mathmagic)(int, int);
  
  printf("%d\n", add(4,5));
  mathmagic = add;
  printf("%d\n", mathmagic(4,5));
  mathmagic = sub;
  printf("%d\n", mathmagic(4,5));

  /* Pointer to a function that takes 2 pointers to ints and returns an int */
  int (*multmagic)(int *, int *);

  multmagic = pmult;
  int ii = 5, jj = 6;
  printf("%d\n", multmagic(&ii,&jj));
}

void *comp1() {
  return NULL;
}

void _comp2(){
  printf("in _comp2\n");
}

char returnschar(){
  return 'x';
}

char alsoReturnschar(){
  return 'y';
}

/* x: function returning pointer to array[] of pointer to function returning char */
char (*(*x1())[])(){
  static char (*x[])() = {&returnschar, &alsoReturnschar};
  return &x;
}

void playWithComplexDeclarations(){
  printf("\nargv: pointer to pointer to char\n");
  char **argv; /* argv: pointer to pointer to char */
  char a = 'x';
  char *_a = &a;
  argv = &_a;
  printf("**argv = %c\n", **argv);

  printf("\ndaytab1: pointer to array[13] of int\n");
  int (*daytab1)[13]; /* daytab1: pointer to array[13] of int */
  int d[13] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 13};
  daytab1 = &d;
  printf("(*daytab1)[4]=%d\n", (*daytab1)[4]);
  printf("**daytab1=%d\n", **daytab1);
  printf("++**daytab1=%d\n", ++**daytab1);

  printf("\ndaytab2: array[13] of pointer to int\n");
  int *daytab2[13]; /*daytab2: array[13] of pointer to int */
  for(int i = 0; i < 13; i++){
    daytab2[i] = &d[i];
  }
  printf("*daytab2[11]=%d\n", *daytab2[11]);

  printf("\ncomp1: function returning pointer to void\n");
  printf("comp1() = %p\n", comp1());

  printf("\ncomp2: pointer to function returning void\n");
  void (*comp2)(); /* comp2: pointer to function returning void */
  comp2 = &_comp2;
  comp2 = _comp2; // same
  printf("*comp2=%p\n", *comp2); // the address of a function
  printf("(*comp2)()\n");
  (*comp2)();
  printf("comp2=%p\n", comp2); // magically the same address
  printf("comp2()\n");
  comp2();

  printf("\nx1: function returning pointer to array[] of pointer to function returning char\n");
  //my first attempt
  printf("((*(x1()))[0])() = %c\n", ((*(x1()))[0])());// don't need to wrap the x1 because * is lower precedence than ()
  // my second attempt
  printf("((*x1())[0])() = %c\n", ((*x1())[0])());// I'm not resolving the pointer to function to a function here, sloppy
  //my third attempt
  printf("((*x1())[0])() = %c\n", (*(*x1())[0])());// ok so now resolving the function before caling.. same as the decl... happy days
  printf("((*x1())[1])() = %c\n", (*(*x1())[1])());// ok so now resolving the function before caling.. same as the decl... happy days
  
  char (*(*x2[3])())[5]; /* x2: array[3] of pointer to function returning pointer to array[S] of char */
}

void playWithUnions(){
  printf("\nUnions\n");
  enum thingType {IS_INT, IS_FLOAT, IS_STRING};

  union u_thing {
    int ival;
    float fval;
    char *sval;
  };

  struct aThing {
    int typeOfThing;
    union u_thing actualThing;
  } thing;

  thing.typeOfThing = IS_INT;
  thing.actualThing.ival = 42;

  printf("typeOfThing=%d\n", thing.typeOfThing);
  if(thing.typeOfThing == IS_INT){
    printf("thing.actualThing.ival=%d\n", thing.actualThing.ival);
  }

  thing.typeOfThing = IS_STRING;
  thing.actualThing.sval = "Now I'm a string!";

  printf("typeOfThing=%d\n", thing.typeOfThing);
  if(thing.typeOfThing == IS_STRING){
    printf("thing.actualThing.sval=%s\n", thing.actualThing.sval);
  }


}