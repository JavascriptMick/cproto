#include <stdio.h>
#include <assert.h>

int day_of_year(int, int, int);
void month_day(int, int, int *, int *);

int main(){
  int doy = day_of_year(2019, 6, 26);
  printf("doy %d\n", doy);

  int month, day;
  month_day(2019, doy, &month, &day);
  printf("month %d, day %d\n", month, day);

  printf("------ error cases ------\n");
  /* null pointer - much better than a segmentation fault that is hard to track */
  printf("*** null pointer ***\n");
  int *badday;
  month_day(2019, doy, &month, badday);

  /* bad year val */
  printf("*** bad year val ***\n");
  day_of_year(-1, 6, 26);
}

static char daytab[2][13] = {
  {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
  {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

/* day_of_year: set day of year from month & day  */
int day_of_year(int year, int month, int day)
{
  assert(year >= 1);
  assert(month >=1 && month <=12);


  int i, leap;
  leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
  assert(day >=1 && day <= daytab[leap][month]);
  for (i = 1; i < month; i++)
    day += daytab[leap][i];
  return day;
}

/* month_day:set month ,day from day of year */
void month_day(int year, int yearday, int *pmonth, int *pday)
{
  assert (year > 0);
  assert (yearday > 0 && yearday <= 365);
  assert (pmonth != NULL);
  assert (pday != NULL);

  int i, leap;
  leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
  for (i = 1; yearday > daytab[leap][i]; i++)
    yearday -= daytab[leap][i];

  *pmonth = i;
  *pday = yearday;
}