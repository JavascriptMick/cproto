#include <stdio.h>

int mangle(int theArray[]);

int main() {
  printf("\\0, 0, 1 and 33 as characters\n");
  putchar('\0');
  putchar(0);
  putchar('\n');
  putchar(1);
  putchar('\n');
  putchar(33);
  putchar('\n');

  int i;
  int myArray[10];
  for(i = 0; i < 10; ++i)
    myArray[i] = i;
  
  mangle(myArray);
  
  for(i = 0; i < 10; ++i)
    printf("%d ", myArray[i]);
    printf("\n");
}

int mangle(int theArray[]) {
  // int myArrayCopy[10];  //wierd, gotta specify length
  // myArrayCopy = theArray; //don work.. unnasignable

  theArray[3] = 42;
  return 0;
}