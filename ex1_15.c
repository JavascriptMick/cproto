#include <stdio.h>

float farentoc(int fahr);

/* print Fahrenheit to Celcius Table */
int main()
{
  int fahr;
  for ( fahr = 0; fahr <= 300; fahr = fahr + 20 ) {
    printf("%3d %6.1f\n", fahr, farentoc(fahr));
  }
}

float farentoc(int fahr){
  float celcius;
  celcius = (5.0/9.0) * (fahr-32.0);
  return celcius;
}