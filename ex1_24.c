#include <stdio.h>

#define TRUE 1
#define FALSE 0
#define STACKHEIGHT 1000

void initStack();
void dumpStack(); //debugging only I think
void push(char c);
char pop();
char peek();
void testStack();
int isLeft(char c);
int isRight(char c);
int isQuote(char c);
int isMatch(char left, char right);

char stack[STACKHEIGHT];
int stackPointer;

// check c program for syntax errors
// unbalanced parens, brackets and braces
// single and double quotes, comments and escape sequences in char littorals
int main()
{
  int c, lc, inBlockComment, inLineComment, linecounter, inCharLittoral, charCount;
  inBlockComment = FALSE;
  inLineComment = FALSE;
  inCharLittoral = FALSE;
  lc = charCount = 0;
  linecounter = 1;
  initStack();
  // testStack();
  while((c = getchar()) != EOF) {
    if(inBlockComment == FALSE && inLineComment==FALSE){
      if(lc=='/' && c=='/'){
        inLineComment = TRUE;
        c = 0;
      }
      else if(lc=='/' && c=='*'){
        inBlockComment = TRUE;
        c = 0;
      }
      else if(c != 0){
        if(isLeft(c)==TRUE)
          push(c);
        else if(isQuote(c)==TRUE)
          if(isMatch(peek(), c)){
            pop();
            if(c=='\''){
              if(charCount==1 && lc=='\\')
                printf("syntax error on line %d, invalid character littoral %c\n", linecounter, lc);
              inCharLittoral = FALSE;
              charCount = 0;
            }  
          }
          else{
            push(c);  //tricky, quotes are not left or right, just push, something else will fail
            if(c=='\'')
              inCharLittoral = TRUE;
          }
        else if(isRight(c)==TRUE)
          if(isMatch(peek(), c))
            pop();
          else
            printf("syntax error on line %d opening %c does not match closing %c\n", linecounter, peek(), c);
        else {
          if(inCharLittoral==TRUE)
            if(++charCount > 2){
              printf("syntax error on line %d, too many characters in character littoral ending with %c%c\n", linecounter, lc, c);
              inCharLittoral = FALSE;
              charCount = 0;
            }
            else if(charCount==2 && lc!='\\'){
              printf("syntax error on line %d, invalid character littoral %c%c\n", linecounter, lc, c);
              inCharLittoral = FALSE;
              charCount = 0;
            }
            else if(charCount==2 && c!='a' && c!='b' && c!='f' && c!='n' && c!='r' && c!='t' && c!='v'){
              printf("syntax error on line %d, invalid character littoral %c%c\n", linecounter, lc, c);
              inCharLittoral = FALSE;
              charCount = 0;
            }
        }
      }
    } else if(inLineComment == TRUE){
      if(c=='\n')
        inLineComment = FALSE;  //lc will become \n, the return is valid
    } else if(inBlockComment == TRUE){
      if(lc=='*' && c=='/'){
        inBlockComment = FALSE;
        c = 0;
      }
    }
    if(c=='\n')
      linecounter++;
    lc = c;
  }
  printf("checking complete\n");
}

int isLeft(char c){
  if(c=='{' || c=='(' || c=='<' || c=='[')
    return TRUE;
  else
    return FALSE;
}

int isRight(char c){
  if(c=='}' || c==')' || c=='>' || c==']')
    return TRUE;
  else
    return FALSE;
}

int isQuote(char c){
  if(c=='\'' || c=='\"')
    return TRUE;
  else
    return FALSE;  
}

int isMatch(char left, char right){
  if(left=='{' && right=='}')
    return TRUE;
  if(left=='(' && right==')')
    return TRUE;
  if(left=='<' && right=='>')
    return TRUE;
  if(left=='[' && right==']')
    return TRUE;
  if(left=='\'' && right=='\'')
    return TRUE;
  if(left=='\"' && right=='\"')
    return TRUE;
  return FALSE;
}

//***** Stack Functions (should be in a module) *******
void initStack() {
  extern char stack[];
  extern int stackPointer;
  int i;
  stackPointer = -1;
  for(i = 0; i < STACKHEIGHT; ++i)
    stack[i] = 0;
}

void dumpStack(){
  extern char stack[];
  extern int stackPointer; 
  printf("stackPointer->%d\n", stackPointer);
  printf("stack->%s\n", stack);
  printf("peek%c\n", peek());
}

void push(char c){
  extern char stack[];
  extern int stackPointer;
  stack[++stackPointer] = c;
}
char pop(){
  extern char stack[];
  extern int stackPointer;  
  char c;
  c = 0;
  if(stackPointer >= 0){
    c = stack[stackPointer];
    stack[stackPointer] = 0;
    stackPointer--;
  }
  return c;
}

char peek(){
  extern char stack[];
  extern int stackPointer;
  if(stackPointer >= 0){
    return stack[stackPointer];
  } else {
    return 0;
  }
}

void testStack(){
  push('x');
  push('y');
  dumpStack();
  printf("pop = %c\n", pop());
  printf("pop = %c\n", pop());
  dumpStack();
}