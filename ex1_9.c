#include <stdio.h>

int main()
{
    int c, nl, spaces;
    nl = 0;
    spaces = 0;
    while((c = getchar()) != EOF)
        if (c == ' ') {
            if (spaces == 0) {
                spaces = 1;
                putchar(c);
            }
        } else {
            if (spaces == 1)
                spaces = 0;
            putchar(c);
        }
}
