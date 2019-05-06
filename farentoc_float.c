#include <stdio.h>

/* print Fahrenheit-Celcius table
   for fahr = 0, 20, .., 300 floating point version*/
main()
{
  float fahr, celcius;
  int lower, upper, step;
  lower = 0;   /* lower limit of temperature table */
  upper = 300; /* upper limit */
  step = 20;   /* step size */

  printf("Fahrenheit-Celcius Table\n");     
  fahr = lower;
  while (fahr <= upper) {
    celcius = (5.0/9.0) * (fahr-32.0);
    printf("%3.0f\t%6.1f\n", fahr, celcius);
    fahr = fahr + step;
  }
}
