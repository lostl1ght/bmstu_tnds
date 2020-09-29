#include "../inc/check.h"
#include "../inc/number.h"

#define CHECK_SUCCESS 0
#define CHECK_FAILURE 1
#define CHECK_WRONG_CHARACTERS 2
#define CHECK_MANT_ERROR 3
#define CHECK_EXP_ERROR 4

int check_str(const char str[])
{
    const char *e_pointer = NULL;
    const char *end;
    size_t e_count;
    if (check_char(str))
        return CHECK_WRONG_CHARACTERS;
    end = str + strlen(str); 
    if ((e_count = count_char('E', str, end)))
        e_pointer = strrchr(str, 'E');
    if ((e_count += count_char('e', str, end)))
        e_pointer = strrchr(str, 'e');
    if (e_count > 1)
        return CHECK_WRONG_CHARACTERS;
    if (check_mantissa(str, e_pointer))
        return CHECK_MANT_ERROR;
    if (e_pointer && check_exponent(e_pointer))
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
    if (check_symb(str, end, 1))
        return CHECK_FAILURE;
    if (count_num(str, end) > MAX_MANTISSA)
        return CHECK_FAILURE;
    return CHECK_SUCCESS;
}

int check_exponent(const char *e_pointer)
{
    const char *end;
    e_pointer++;
    if (!(end = strrchr(e_pointer, '\n')))
        end = e_pointer + strlen(e_pointer);
    if (check_symb(e_pointer, end, 0))
        return CHECK_FAILURE;
    if (count_num(e_pointer, end) > MAX_EXPONENT)
        return CHECK_FAILURE;
    return CHECK_SUCCESS;
}
