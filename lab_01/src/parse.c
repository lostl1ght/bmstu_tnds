#include "../inc/parse.h"

#define PARSE_SUCCESS 0
#define PARSE_FAILURE 1

int parse_number(const char str[], number_t *num)
{
    const char *end_ptr;
    if (!(end_ptr = strpbrk(str, "Ee")))
        end_ptr = str + strlen(str);
    else
    {
        end_ptr++;
        if (sscanf(end_ptr, "%d", &num->exponent) != 1)
            return PARSE_FAILURE;
        end_ptr--;
    }
    end_ptr--;
    while (end_ptr != str - 1)
    {
        if (isdigit(*end_ptr))
        {
            num->mantissa[num->len_m] = *end_ptr - '0';
            num->len_m++;
        }
        else if (*end_ptr == '.' || *end_ptr == ',')
            num->exponent -= num->len_m;
        end_ptr--;
    }

    end_ptr++;
    if (isdigit(*end_ptr) || *end_ptr == '+')
        num->sign_m = 1;
    else if (*end_ptr == '.' || *end_ptr == ',')
        num->sign_m = 1;
    else if (*end_ptr == 'e' || *end_ptr == 'E')
        num->sign_m = 1;
    else if (*end_ptr == '-')
        num->sign_m = -1;

    if (num->len_m > 0)
        remove_zeros(num);
    else
    {
        num->mantissa[0] = 1;
        num->len_m = 1;
    }
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