#include "../inc/check.h"
#include "../inc/number.h"
#include <stdio.h>

#define CHECK_SUCCESS 0
#define CHECK_FAILURE 1
#define CHECK_WRONG_CHARACTERS 2
#define CHECK_MANT_ERROR 3
#define CHECK_EXP_ERROR 4

int check_str(char str[])
{
    char *e_pointer = NULL;
    if (check_char(str))
        return CHECK_WRONG_CHARACTERS;
    if (check_e(str, &e_pointer))
        return CHECK_WRONG_CHARACTERS;
    // if (check_mantissa(str, e_pointer))
    //     return CHECK_MANT_ERROR;
    if (e_pointer && check_exponent(e_pointer))
        return CHECK_EXP_ERROR;
    return CHECK_SUCCESS;
}

int check_char(char *p)
{
    char s;
    while (*p)
    {
        s = *p;
        if (!strpbrk("-+.,1234567890Ee\n", &s))
            return CHECK_FAILURE;
        p++;
    }
    return CHECK_SUCCESS;
}

int check_e(char *p, char **e_pointer)
{
    int e_count = 0;
    while (*p)
    {
        if (*p == 'e' || *p == 'E')
        {
            *e_pointer = p;
            e_count++;
        }
        p++;
    }
    if (e_count > 1)
        return CHECK_FAILURE;
    return CHECK_SUCCESS;
}

// int check_mantissa(char *str, char *e_pointer)
// {
//     return CHECK_SUCCESS;
// }

int check_exponent(char *e_pointer)
{
    int check;
    e_pointer++;
    if (sscanf(e_pointer, "%d", &check) != 1)
        return CHECK_FAILURE;
    if (strrchr(e_pointer, '.') || strrchr(e_pointer, ','))
        return CHECK_FAILURE;
    if (check_exp_len(e_pointer))
        return CHECK_FAILURE;
    return CHECK_SUCCESS;
}

int check_exp_len(char *e_pointer)
{
    if (strrchr(e_pointer, '+'))
    {
        if (*e_pointer != '+')
            return CHECK_FAILURE;
        else
        {
            e_pointer++;
            if (check_len_exp_num(e_pointer))
                return CHECK_FAILURE;
        }
    }
    else if (strrchr(e_pointer, '-'))
    {
        if (*e_pointer != '-')
            return CHECK_FAILURE;
        else
        {
            e_pointer++;
            if (check_len_exp_num(e_pointer))
                return CHECK_FAILURE;
        }
    }
    else
        if (check_len_exp_num(e_pointer))
            return CHECK_FAILURE;
    return CHECK_SUCCESS;
}

int check_len_exp_num(char *p)
{
    size_t len;
    len = strlen(p);
    if (strrchr(p, '\n'))
    {
        if (len > MAX_EXPONENT + 1)
            return CHECK_FAILURE;
    }
    else if (len > MAX_EXPONENT)
        return CHECK_FAILURE;
    return CHECK_SUCCESS;
}