# Initial Impressions
- Everything is super clean, intuitive and minimal, this language is awesome!
- Where is my declare and assign in one statement?
- define is super powerful and feels very close to the compiler.  Are these the same as macros?
```
#define TOOMUCHPOWER printf("Hello World")
```
- getchar() is wierd in interactive mode, the chars only get got when iffen you press the enter button but they echo all the time?!.  Googol that and get the first sniff of behaviour differences in different os's (i'm on a mac).. here we go.

# 1.6  Arrays
- Still clean and nice 

# 1.8 Arguments--Call by Value
- pass by value seems good... at least it's explicit.  Makes you think about what you have been assuming all along.  I think the same, rarely use a function to mess with parameters.  arrays though... I guess this makes sense.

# 1.9 Character Arrays
- needing to specify array size is a drag, have been taking this for granted
- declaring index variables (int i) outside of a for means you can terminate the for with a condition and use the value of i without a break statement.  Hadn't thought of this.

# 1.10 - External Variables and Scope
- "No Globals!"... the whole include/omit the extern keyword thing is a recipe for disaster, just invites problems.

# Chapter 1 exercises
Exercises were a slog but definately worth it.  Getting the hang of it

## Missing
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
In one statement, just so much cleaner and more cohesive.
