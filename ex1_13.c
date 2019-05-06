#include <stdio.h>

//Histogram of word lengths
int main()
{
  int c, ccount, i, h, maxh;
  ccount = maxh = 0;

  // number of words of a given length
  // nwlength[0] is unused
  // nwlength[3] = number of 3 letter words
  // nwlength[9] = number of words with >= 9 letters
  int nwlength[10];
  for(i = 0; i < 10; ++i)
    nwlength[i] = 0;

  while((c = getchar()) != EOF){
    if(c == '\n' || c == '\t' || c == ' '){
      if(ccount > 0){
        if(ccount >= 9)
          ccount = 9;

        ++nwlength[ccount];
        if(nwlength[ccount] > maxh)
          maxh = nwlength[ccount];
        ccount = 0;
      }
    } else
      ++ccount;
  }

  //print out the histogram with horizontal bars
  printf("Histogram with horizontal bars\n");
  for(i = 1; i < 10; ++i) {
    putchar('0' + i);
    putchar(':');
    for(h = 0; h < nwlength[i];++h)
      putchar('*');
    putchar('\n');
  }
  putchar('\n');

  //print out the histogram with vertical bars
  printf("Histogram with vertical bars\n");
  for(h = maxh; h>0; --h) {
    printf("%2d|", h);
    for(i = 1; i < 10; ++i) {
      if(nwlength[i] >= h)
        putchar('*');
      else
        putchar(' ');
    }
    putchar('\n');
  }
  printf("   __________\n");
  printf("   ");
  for(i = 1; i < 10; ++i) {
    putchar('0' + i);
  }
  putchar('\n');
}