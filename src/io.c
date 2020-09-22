#include "../inc/io.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define IO_SUCCESS 0
#define IO_FAILURE 1

int input_str(char str[])
{
    printf("Input number: ");
    if (!fgets(str, MAX_SYMBOLS + 2, stdin))
        return IO_FAILURE;
    return IO_SUCCESS;
}

int parse_number(char str[], number_t *num)
{

    char *p;
    p = str + strlen(str) - 1;
    while (p != str - 1)
    {
        if (isdigit(*p))
        {
            num->mantissa[num->len_m] = *p - '0';
            num->len_m++;
        }
        p--;
    }
    return IO_SUCCESS;
}