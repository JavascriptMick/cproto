#include <stdio.h>
#include <ctype.h>
#include <math.h>

double atof(char s[]);
void testatof(char s[]);

int main()
{
  testatof("-42.13e6");
  testatof("796.01e-3");
  testatof("0");
  testatof("100");
  
}

void testatof(char s[]){
  double result = atof(s);
  printf("%s -> \t\t%f\n", s, result);
}

double atof(char s[])
{
  double val, power, expval;
  int i, sign, expsign;
  for (i = 0; isspace(s[i]); i++) /* skip whitespace*/
    ;

  //todo - factor out into 'valfromstring' function and call thrice
  sign = (s[i] == '-') ? -1 : 1;
  if (s[i] == '+' || s[i] == '-')
    i++;
  for (val = 0.0; isdigit(s[i]); i++)
    val = 10.0 * val + (s[i] - '0');
    
  if (s[i] == '.')
    i++;

  // valfromstring?  
  for (power = 1.0; isdigit(s[i]); i++) {
    val = 10.0 * val + (s[i] - '0');
    power *= 10.0;
  }

  if (s[i] == 'e' || s[i] == 'E')
    i++;

  // valfromstring
  expsign = (s[i] == '-') ? -1 : 1;
  if (s[i] == '+' || s[i] == '-')
    i++;
  for (expval = 0.0; isdigit(s[i]); i++)
    expval = 10.0 * expval + (s[i] - '0');

  return pow(10, expsign * expval) * sign * val / power; 
}