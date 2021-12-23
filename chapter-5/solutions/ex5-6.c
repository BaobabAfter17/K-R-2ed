/* chapter 4.2, p71; pointer version */
#include <ctype.h>

/* atof: convert string s to double */
double atof(char *s)
{
    double val, power;
    int sign;

    for (; isspace(*s); s++) /* skip the white space */
        ;
    sign = (*s == '-') ? -1 : 1;
    if (*s == '+' || *s == '-')
        s++;
    for (val = 0.0; isdigit(*s); s++)
        val = 10.0 * val + (*s - '0');
    if (*s == '.')
        s++;
    for (power = 1.0; isdigit(*s); s++)
    {
        val = 10.0 * val + (*s - '0');
        power *= 10.0;
    }
    return sign * val / power;
}
