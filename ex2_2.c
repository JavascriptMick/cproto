#include <stdio.h>

int main()
{
    int lim = 42;
    int i, c;
    char s[100];

    // for (i=0; i<lim-1 && (c=getchar()) != '\n' && c != EOF; ++i)
    //     s[i] =c;

    // not using || and && makes things less compact
    for (i=0; i<lim-1; ++i){
        c = getchar();
        if(c == '\n')
            break;
        if(c == EOF)
            break;
        s[i] =c;
    }
        
    printf("%s\n", s);
}