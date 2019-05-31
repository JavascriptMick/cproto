#include <stdio.h>
enum boolean { FALSE, TRUE};

void squeeze(char s[], char c[]);
/*
Write an alternate version of squeeze (s 1,s2) that deletes
each character in s 1 that matches any character in the string s2
*/
int main()
{
    char s[] = "zThe quick jjbrown foxzzz";
    squeeze(s, "zja");
    printf("%s\n", s);
}

void squeeze(char s[], char c[])
{
    int i, j, k, found;

    for(i = j = 0; s[i] != '\0'; i++) {
        found = FALSE;
        for(k=0; c[k] != '\0'; k++)
            if(s[i]==c[k])
                found = TRUE;
        if(found == FALSE)
            s[j++] = s[i];
    }
    s[j] = '\0';
}
