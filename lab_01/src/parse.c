#include "../inc/parse.h"

#define PARSE_SUCCESS 0
#define PARSE_FAILURE 1

int parse_number(char str[], number_t *num)
{
    char *p;
    if (!(p = strpbrk(str, "Ee")))
        p = str + strlen(str);
    else
    {
        p++;
        if (sscanf(p, "%d", &num->exponent) != 1)
            return PARSE_FAILURE;
        p--;
    }
    p--;
    while (p != str - 1)
    {
        if (isdigit(*p))
        {
            num->mantissa[num->len_m] = *p - '0';
            num->len_m++;
        }
        else if (*p == '.' || *p == ',')
            num->exponent -= num->len_m;
        p--;
    }
    p++;
    if (isdigit(*p) || *p == '+')
        num->sign_m = 1;
    else if (*p == '-')
        num->sign_m = -1;
    return PARSE_SUCCESS;
}