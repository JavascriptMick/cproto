#include <stdio.h>
#include <string.h>

int strrindex(char s[], char t[]);

int main()
{
  char s[] = "Mellow Yellow!";
  char t[] = "ell";
  int result = strrindex(s, t);
  printf("%d\n", result);
}

/* strindex: return index of t in s, -1 if none */
int strrindex(char s[], char t[])
{
  int i, j, k;
  for (i = strlen(s) - 1; s[i] != '\0'; i--) {
    for (j=i, k=0; t[k]!='\0' && s[j]==t[k]; j++, k++)
      ;
    if (k > 0 && t[k] == '\0')
      return i;
  }
  return -1;
}