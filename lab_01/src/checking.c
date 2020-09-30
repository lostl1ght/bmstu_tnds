#include "checking.h"

int check_str(const char str[])
{
    const char *e_ptr = NULL;
    const char *end;
    size_t e_count1, e_count2;
    if (check_char(str))
        return CHECK_WRONG_CHARACTERS;
    end = str + strlen(str); 
    if ((e_count1 = count_char('E', str, end)))
        e_ptr = strrchr(str, 'E');
    else if ((e_count2 = count_char('e', str, end)))
        e_ptr = strrchr(str, 'e');
    if (e_count1 + e_count2 > 1)
        return CHECK_WRONG_CHARACTERS;
    if (check_mantissa(str, e_ptr))
        return CHECK_MANT_ERROR;
    if (e_ptr && check_exponent(e_ptr))
        return CHECK_EXP_ERROR;
    return CHECK_SUCCESS;
}

int check_char(const char *p)
{
    char s[2];
    s[1] = '\0';
    while (*p)
    {
        s[0] = *p;
        if (!strpbrk("-+.,1234567890Ee\n", s))
            return CHECK_FAILURE;
        p++;
    }
    return CHECK_SUCCESS;
}

size_t count_char(const char c, const char *start, const char *end)
{
    size_t count = 0;
    while (start < end)
    {
        if (*start == c)
            count++;
        start++;
    }
    return count;
}

size_t count_num(const char *start, const char *end)
{
    size_t count = 0;
    char s[2];
    s[1] = '\0';
    while (start < end)
    {
        s[0] = *start;
        if (strpbrk("1234567890", s))
            count++;
        start++;
    }
    return count;
}

int check_symb(const char *start, const char *end, const size_t dot_count)
{
    size_t count;
    size_t count_dt, count_cm;
    count = count_char('-', start, end);
    if (count > 1)
        return CHECK_FAILURE;
    else if (count == 1 && *start != '-')
        return CHECK_FAILURE;
    count = count_char('+', start, end);
    if (count > 1)
        return CHECK_FAILURE;
    else if (count == 1 && *start != '+')
        return CHECK_FAILURE;
    if ((count_dt = count_char('.', start, end)) > dot_count)
        return CHECK_FAILURE;
    if ((count_cm = count_char(',', start, end)) > dot_count)
        return CHECK_FAILURE;
    if (count_cm && count_dt)
        return CHECK_FAILURE;
    return CHECK_SUCCESS;
}

int check_mantissa(const char *str, const char *end)
{
    if (!end)
        end = str + strlen(str);
    if (str == end || (str + 1 == end && (*str == '.' || *str == ',' || *str == '-' || *str == '+')))
        return CHECK_FAILURE;
    if (str + 2 == end && (*(str + 1) == '.' || *(str + 1) == ',') && (*str == '-' || *str == '+'))
        return CHECK_FAILURE;
    if (!strcmp(str, ".") || !strcmp(str, "-") || !strcmp(str, "+"))
        return CHECK_FAILURE;
    if (check_symb(str, end, 1))
        return CHECK_FAILURE;
    if (count_num(str, end) > MAX_MANTISSA)
        return CHECK_FAILURE;
    return CHECK_SUCCESS;
}

int check_exponent(const char *e_ptr)
{
    const char *end;
    e_ptr++;
    if (!(end = strrchr(e_ptr, '\n')))
        end = e_ptr + strlen(e_ptr);
    if (check_symb(e_ptr, end, 0))
        return CHECK_FAILURE;
    if (count_num(e_ptr, end) > MAX_EXPONENT)
        return CHECK_FAILURE;
    return CHECK_SUCCESS;
}
