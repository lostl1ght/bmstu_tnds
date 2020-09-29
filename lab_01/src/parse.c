#include "parse.h"

#define PARSE_SUCCESS 0
#define PARSE_FAILURE 1

int parse_number(const char str[], number_t *num)
{
    const char *e_ptr;
    int zero_flag = 1;
    if (!(e_ptr = strpbrk(str, "Ee")))
        e_ptr = str + strlen(str);
    else
    {
        e_ptr++;
        if (sscanf(e_ptr, "%d", &num->exponent) != 1)
            return PARSE_FAILURE;
        e_ptr--;
    }
    e_ptr--;
    while (e_ptr != str - 1)
    {
        if (isdigit(*e_ptr))
        {
            num->mantissa[num->len_m] = *e_ptr - '0';
            num->len_m++;
        }
        else if (*e_ptr == '.' || *e_ptr == ',')
            num->exponent -= num->len_m;
        e_ptr--;
    }

    e_ptr++;
    if (isdigit(*e_ptr) || *e_ptr == '+')
        num->sign_m = 1;
    else if (*e_ptr == '.' || *e_ptr == ',')
        num->sign_m = 1;
    else if (*e_ptr == 'e' || *e_ptr == 'E')
        num->sign_m = 1;
    else if (*e_ptr == '-')
        num->sign_m = -1;

    for (size_t i = 0; i < num->len_m; i++)
        if (num->mantissa[i] != 0)
            zero_flag = 0;
    
    if (zero_flag)
    {
        num->len_m = 1;
        num->exponent = 0;
        num->sign_m = 1;
    }

    if (num->len_m > 1)
        remove_zeros(num);
    else if (num->len_m == 0)
        return PARSE_FAILURE;
    return PARSE_SUCCESS;
}

void remove_zeros(number_t *num)
{
    for (size_t i = num->len_m -1; num->mantissa[i] == 0; i--)
        num->len_m--;

    while (num->mantissa[0] == 0)
    {
        for (size_t j = 0; j < num->len_m - 1; j++)
            num->mantissa[j] = num->mantissa[j + 1];
        num->mantissa[num->len_m - 1] = 0;
        num->len_m--;
        num->exponent++;
    }
}