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

## 5.12 Complicated Declarations
ok, so the whole, 'lets mansplain the complex declaration thing with a complicated set of new words that don't help and a complicated parsing function that doesn't work all the time'.... thing... was a bit of a waste of time but the examples are excellent.  I ended up actually implementing some of these complicated declarations (coding the rhs) and this was infinitely more useful.

In the end, what helped was taking a "once you have a" approach.. to explain.  If faced with this horrible abomination: -
```
char (*(*x2[3])())[5];
```
Imagine you have an x2 in your hand...
The first thing you do is apply an array indexer to it ('[' has a higher precedence than *)... so this means x2 is an array of something

Then you de-reference .... so x2 must be an array of pointers to something

then you take you (bracket and) invoke like a function.. so x2 must be an array of pointers to a function

then you de-reference the result of the function.. so x2 must be an array of pointers to a function that returns a pointer .. to something

then you apply an array indexer.. so in the end, x2 must be an array[3] of pointer to function returning pointer to array[S] of char.

This works in my brain and is alluded too in this quote
```
int *ip;
```
"
is intended as a mnemonic;it says that the expression *ip is an int. The syntax of the declaration for a variable mimics the syntax of expressions in which the variable might appear.
"

# 6. Structures
Structures make sense, even pointers to structures and the arrow syntax was ok.  the stuff on self referential structures was cool and I was stoked to implement hashmap and linked list finally.

## 6.7 typedef
This seams like trouble brewing to me.  simple language, simple basic constructs close to the metal and nobody can get confused....Oh, and here, make up your own names for stuff! build a DSL, make everybody learn a new thing for each implementation.  Here is a typedef for String hooray.. except I want it to be STRING, whats the convention?

I get that this is probably seemed like a good idea to start building up domain problems and to prevent everybody going bananas with complex declarations but I have only just figured out the basics and now without even seeing it, I know there is going to be a narrative of differing opinions and competing conventions that will be warring throughout the archealogical commit history.  This is exactly the type of bs I want to avoid. 

## 6.8 Unions
more trouble... not sure what crazy circumstance makes this a good idea.
