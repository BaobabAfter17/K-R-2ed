/* chapter 4.2, p71 */

#include <ctype.h>

/* atof: convert string s to double */
double atof(char s[])
{
    double val, power;
    int i, sign, exp;

    for (i = 0; isspace(s[i]); i++) /* skip the white space */
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }
    val = sign * val / power;

    if (s[i] == 'e' || s[i] == 'E') {
        sign = (s[++i] == '-') ? -1 : 1;
        if (s[i] == '+' || s[i] == '-')
            i++;
        for (exp = 0; isdigit(s[i]); i++)
            exp = exp * 10 + (s[i] - '0');
        /* In most machines, 0.1 is represented as slightly less 
         * than 0. 1 and therefore 10.0 times 0. 1 is rarely 1 .0.
         * Repeated division by 10 is better than repeated multiplication by 0.1,
         * but there is still a loss of accuracy. */
        if (sign == 1) {
            while (exp-- > 0)   /* positive exponent */
                val *= 10.0;
        } else {
            while (exp-- > 0)   /* negative exponent */
                val /= 10.0;
        }
    }
    return val; 
}
