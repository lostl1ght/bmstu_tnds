#include "../inc/parse.h"
#include <string.h>
#include <ctype.h>

#define PARSE_SUCCESS 0
#define PARSE_FAILURE 1

int parse_number(char str[], number_t *num)
{

    char *p;
    if (!(p = strpbrk(str, "Ee")))
        p = str + strlen(str);
    p--;
    while (p != str - 1)
    {
        if (isdigit(*p))
        {
            num->mantissa[num->len_m] = *p - '0';
            num->len_m++;
        }
        else if (*p == '.')
        {
            num->exponent -= num->len_m;
        }
        p--;
    }
    return PARSE_SUCCESS;
}