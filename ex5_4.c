#include <stdio.h>

int strend(char *s, char *t);

int main()
{
    char s[] = "Henry Manfrenjensen";
    printf("%s\n", s);
    printf("ensen:%d\n", strend(s, "ensen"));
    printf("n:%d\n", strend(s, "n"));
    printf(":%d\n", strend(s, ""));
    printf("osen:%d\n", strend(s, "osen"));
    printf("Henry:%d\n", strend(s, "Henry"));
    printf("fren:%d\n", strend(s, "fren"));
}

int strend(char *s, char *t)
{
    char *ss = s;
    char *tt = t;
    while(*s)
        s++;
    while(*t)
        t++;
    while((*--s == *--t) && s >= ss && t >= tt)
        ;
    return (t < tt)?1:0;
}
