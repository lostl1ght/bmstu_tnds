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
    if (isdigit(*p) || *p == '+' || *p == '.' || *p == ',')
        num->sign_m = 1;
    else if (*p == '-')
        num->sign_m = -1;
    remove_zeros(num);
    return PARSE_SUCCESS;
}

void remove_zeros(number_t *num)
{
    size_t i = num->len_m -1;
    while (num->mantissa[i] == 0)
    {
        num->len_m--;
        i--;
    }
    i = 0;
    while (num->mantissa[i] == 0)
    {
        for (size_t j = i; j < num->len_m - 1; j++)
            num->mantissa[j] = num->mantissa[j + 1];
        num->mantissa[num->len_m - 1] = 0;
        num->len_m--;
        num->exponent--;
    }
}