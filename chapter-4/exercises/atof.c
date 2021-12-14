/* ex4-2, p73 */

#include <ctype.h>

/* atof: convert scientifc notation s to double */
double atof(char s[])
{
    double val, power, epower, esign;
    int i, sign, eint;

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

    if (s[i] == 'e' || s[i] == 'E') /* optioanlly signed exponent */
        i++;
    /* C answer book, p72: In most machines, 0.1 is represented as slightly less
     * than 0. 1 and therefore 10.0 times 0. 1 is rarely 1 .0.
     * Repeated division by 10 is better than repeated multiplication by 0.1,
     * but there is still a loss of accuracy. */
    esign = (s[i] == '-') ? 0.1 : 10.0;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (eint = 0; isdigit(s[i]); i++)
        eint = eint * 10 + (s[i] - '0');
    for (epower = 1.0; eint > 0; eint--)
        epower *= esign;

    return sign * val / power * epower;
}
