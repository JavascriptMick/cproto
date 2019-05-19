- Everything is super clean, intuitive and minimal, this language is awesome!
- Where is my declare and assign in one statement?
- define is super powerful and feels very close to the compiler.  Are these the same as macros?
```
#define TOOMUCHPOWER printf("Hello World")
```
- getchar() is wierd, the chars only get got when iffen you press the enter button but they echo all the time?!.  Googol that and get the first sniff of behaviour differences in different os's (i'm on a mac).. here we go.

#1.6  Arrays
- Still clean and nice 

#1.8 Arguments--Call by Value
- pass by value seems good... at least it's explicit.  Makes you think about what you have been assuming all along.  I think the same, rarely use a function to mess with parameters.  arrays though... I guess this makes sense.

#1.9 Character Arrays
- needing to specify array size is a drag, have been taking this for granted
- declaring index variables (int i) outside of a for means you can terminate the for with a condition and use the value of i without a break statement.  Hadn't thought of this.

#1.10 - External Variables and Scope
- "No Globals!"... the whole include/omit the extern keyword thing is a recipe for disaster, just invites problems.