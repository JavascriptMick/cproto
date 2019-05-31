#include <stdio.h>

/*
Write the function any(s1,s2), which returns the first location
in the string s1 where any character from the string s2 occurs,
or -1 if s 1 contains no characters from s2. (The standard library
function strpbrk does the same job but returns a pointer to the
location.
*/

int any(char s1[], char s2[]);

int main()
{
    char s[] = "The quick brown fox";
    printf("Found at %d\n", any(s, "zba"));
    printf("Found at %d\n", any(s, "x"));
    printf("Found at %d\n", any(s, "Tz"));
}

int any(char s1[], char s2[])
{
    int i, k, found;

    for(i = 0; s1[i] != '\0'; i++) {
        for(k=0; s2[k] != '\0'; k++)
            if(s1[i]==s2[k])
                return i;
    }
    return -1;
}
