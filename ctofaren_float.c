#include <stdio.h>

/* print Celcius-Fahrenheit table
   for celcius = -40, -20, .., 300 floating point version*/
main()
{
  float fahr, celcius;
  int lower, upper, step;
  lower = -40;   /* lower limit of temperature table */
  upper = 300; /* upper limit */
  step = 20;   /* step size */

  printf("Celcius-Fahrenheit Table\n");     
  celcius = lower;
  while (celcius <= upper) {
    fahr = (9.0/5.0) * celcius + 32;
    printf("%3.0f\t%6.1f\n", celcius, fahr);
    celcius = celcius + step;
  }
}
