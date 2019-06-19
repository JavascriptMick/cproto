#include <stdio.h>

void _strcat(char s[], char t[]);
void pstrcat(char *s, char *t);

int main()
{
    char s[100] = "hello";
    char t[] = " dolly";
    pstrcat(s, t);
    printf("%s\n", s);
}

/* strcat: concatenate t to end of s; s must be big enough */
void _strcat(char s[], char t[])
{
    int i, j;
    i = j = 0;
    while (s[i] != '\0') /* find end of s */
        i++;
    while ((s[i++] = t[j++]) != '\0') /* copy t */
        ;
}

void pstrcat(char *s, char *t)
{
    while(*s)
        s++;
    while((*s++ = *t++)){
        ;
    }
}