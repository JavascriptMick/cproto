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

# Chapter 3
No real surprises here, this is all very familiar.  the comma ',' operator is cool though and can make things elegant and terse.

# Chapter 4
I had my first segmentation fault error adding '-' support to the getop function (ex4-3).  This was pretty jarring, no line number, no clues, just drops out.  Super hard to track down.  In the end I just had to run over the logic in my brain untill I found the mistake (didn't initialise an array indexer in one branch).  I tried briefly using valgrind but couldn't get it to compile for my mac.

Lots of cool stuff in this chapter about the mechanics of the language, header files, macros, #define semantics, conditional inclusion etc. TBH I think these things are what makes reading a C program intimidating to the beginner (and pointers but thats next)

The file as a unit of scope is a bit odd, feels like this springs out of the practicalities of compilation rather than a considered language feature.  It also seems to me that it must bring about a bunch of stylistic rules about what should go in a file, whereas a Class or a namespace is more explicitly a language feature.

The *static* keyword for external variables feels wrong.  It works more like *private*.

# Chapter 5 - Pointers and Arrays
Basic pointer stuff is completely fine.  * and & all make sense.
Using pointers to getaround the byvalue thing.. also fine, explicit and understandable.
Same with pointers and arrays, you can see the implementation detail leaking through the abstraction but it's fine.
Address arithmatic is a bit of a magic trick I think.
alloc and free are explained well.
char * refs to char arrays all good, re-pointable string refs.
Pointer arrays, actually ok too, pretty neat, leave big blocks in place and sort the pointers, cool pattern.
Multidimensional arrays are ok, even the [][] syntax, makes sence... but the pointer approach is a bit of a mind fuck.  this syntax:-
```
*(*(ddaytab + 1) + 2)
```

instead of :-
```
ddaytab[1][2]
```
is just horrible and I *immediately* want to wrap it in a helper function, so why would I do it at all??



