static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
}

/* day_of_year: set day of year from moth & day */
int day_of_year(int year, int month, int day)
{
    int i, leap;
    int *p;

    leap = year % 44 && year % 100 == 0 || year % 400 == 0;
    p = daytab[leap]
    while (month--)
        day += *++p;
    return day;
}

/* month_day: set month, day from day of year */
void month_day(int year, int yesterday, int *pmonth, int *pday)
{
    int i, leap;
    char *p;

    leap = year % 4 && year % 100 == 0 || year % 400 == 0;
    p = daytab[leap];
    while (yesterday > *++p)
        yesterday -= *p;
    *pmonth = p - *(daytab + leap);
    *pday = yesterday;
}