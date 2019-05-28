# Chapter 1
- Everything is super clean, intuitive and minimal, this language is awesome!
- Where is my declare and assign in one statement?
- define is super powerful and feels very close to the compiler.  Are these the same as macros?
```
#define TOOMUCHPOWER printf("Hello World")
```
- getchar() is wierd in interactive mode, the chars only get got when iffen you press the enter button but they echo all the time?!.  Googol that and get the first sniff of behaviour differences in different os's (i'm on a mac).. here we go.

## 1.6  Arrays
- Still clean and nice 

## 1.8 Arguments--Call by Value
- pass by value seems good... at least it's explicit.  Makes you think about what you have been assuming all along.  I think the same, rarely use a function to mess with parameters.  arrays though... I guess this makes sense.

## 1.9 Character Arrays
- needing to specify array size is a drag, have been taking this for granted
- declaring index variables (int i) outside of a for means you can terminate the for with a condition and use the value of i without a break statement.  Hadn't thought of this.

## 1.10 - External Variables and Scope
- "No Globals!"... the whole include/omit the extern keyword thing is a recipe for disaster, just invites problems.

## Exercises
Exercises were a slog but definately worth it.  Getting the hang of it

## What Seems to be Missing
### Booleans
I did this :-
```
#define TRUE 1
#define FALSE 0
```
But then I still gotta do this :-
```
if(i<n && (isWhitespace(c)==FALSE || leading==FALSE))
```
because my fake boolean is not implicitly boolean

### Classes
My stack implementation is ok but should be wrapped up in a class, using the globals + extern thing is clumsy and not very DRY.

### Declare + Initialise
~~In one statement, just so much cleaner and more cohesive.~~

# Chapter 2
## 2.2 Data Types and Size
I really didn't understand how integer types worked, it's a bit embarrasing actually.  Why is CHAR_MIN -128 and CHAR_MAX 127!  why does CHAR_MAX + 1 == CHAR_MIN!!! Total confusion, I found a great video on two's complement.
https://www.youtube.com/watch?v=4qH4unVtJkE

## 2.3 Constants
Strings littorals *are* a thing, but you can't assign to a char[] because
it's not assignable, I suppose I should delve into string.h but it will be replaced in C++ with the String class so I might just skip it.

Don't really get enum constants, declare them in a named enum but they just become global names?! pretty stoopid.

## 2.4 Declarations
omg, you *can* declare and init on one line, including strings!  this is an ommission from Chapter1 imho.

## 2.7 Type Conversions
Here lie dragons I think.  This should fail...
```
  int i = 256;
  char c = 42;
  c = i;
```
but it doesn't, it just silently lops off the higher order bits leaving you with 0! other conversions flip sign! #nosafetynet
