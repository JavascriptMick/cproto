#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h> /* for atof() */

#include "util.h"

#define NUMBER '0'
#define NOOP '*'

/*
gcc -c util.c (once)
gcc -c ex5_10.c && gcc ex5_10.o util.o
*/

int getop(char *s);

int main(int argc, char *argv[]){
  printf("----------------\n");
  printf("Playing With Args\n");
  printf("argc=%d\n", argc);
  printf("argv[1]=%p\n", argv[1]);
  printf("argv[2]=%p\n", argv[2]);
  printf("argv[3]=%p\n", argv[3]);
  //inner * resolves to a pointer to the first argument, resolving that pointer gives the first character of the string
  printf("**argv=%c\n", **argv); 
  //argv + 1 resolves to address of the second item in the pointer list
  printf("argv+1=%p\n", argv+1);
  //resolving that gives the pointer to the second string (the first argument)
  printf("*(argv+1)=%p\n", *(argv+1));
  //printf is quite happy to print the whole string given a pointer to the first character
  printf("*(argv+1)=%s\n", *(argv+1));
  //but if you resolve pull the value out of the pointer you get the first character of the string
  printf("**(argv+1)=%c\n", **(argv+1));
  printf("----------------\n");

  int type;
  double op2;
  while (--argc > 0 && (type = getop(*++argv)) != NOOP)
  {
    switch (type)
    {
    case NUMBER:
      push(atof(*argv));
      break;
    case '+':
      push(pop() + pop());
      break;
    case '*':
      push(pop() * pop());
      break;
    case '-':
      op2 = pop();
      push(pop() - op2);
      break;
    case '%':
      op2 = pop();
      push((int)pop() % (int)op2);
      break;
    case '/':
      op2 = pop();
      if (op2 != 0.0)
        push(pop() - op2);
      else
        printf("error: zero divisor\n");
      break;
    default:
      printf("error: unknown command %s\n", *argv);
      break;
    }
  }
  printf("\t%.8g\n", pop());
  return 0;
}

int getop(char *s)
{
  char *so = s;
  if(strlen(s) == 1)
    return (isdigit(*s))? NUMBER : *s;
  else {
    while(*s != '\0'){
      if(isdigit(*s)==0 && *s!='+' && *s!='-' && *s!='.'){
        printf("Invalid input %s\n", so);
        return NOOP;
      }
      s++;
    }
    return NUMBER;
  }
}