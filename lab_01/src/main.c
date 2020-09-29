#define _USEMINGW_ANSI_STDIO 1
#include <stdio.h>
#include "../inc/number.h"
#include "../inc/io.h"
#include "../inc/parse.h"
#include "../inc/check.h"

#define SUCCESS 0
#define FAILURE 1
#define UNKNOWN -1

int main(void)
{
    char str[LEN];
    int rc;
    number_t num1 = {.len_m = 0, .mantissa = {0}, .exponent = 0};
    number_t num2 = {.len_m = 0, .mantissa = {0}, .exponent = 0};
    // number_t res = {.len_m = 0, .mantissa = {0}, .exponent = 0};
    if (input_str(str))
    {
        puts("Cannot read number. Try again.");
        return FAILURE;
    }
    rc = check_str(str);
    switch (rc)
    {
        case CHECK_SUCCESS:
            break;
        case CHECK_WRONG_CHARACTERS:
            puts("Invalid characters input. Try again.");
            return CHECK_WRONG_CHARACTERS;
        case CHECK_MANT_ERROR:
            puts("Invalid characters in mantissa. Try again.");
            return CHECK_MANT_ERROR;
        case CHECK_EXP_ERROR:
            puts("Invalid characters in exponent. Try again.");
            return CHECK_EXP_ERROR;
        default:
            puts("Unknown error. Try again.");
            return UNKNOWN;
    }  
    if (parse_number(str, &num1))
    {
        puts("Parsing failed. Try again");
        return FAILURE;
    }

    if (input_str(str))
    {
        puts("Cannot read number. Try again.");
        return FAILURE;
    }
    rc = check_str(str);
    switch (rc)
    {
        case CHECK_SUCCESS:
            break;
        case CHECK_WRONG_CHARACTERS:
            puts("Invalid characters input. Try again.");
            return CHECK_WRONG_CHARACTERS;
        case CHECK_MANT_ERROR:
            puts("Invalid characters in mantissa. Try again.");
            return CHECK_MANT_ERROR;
        case CHECK_EXP_ERROR:
            puts("Invalid characters in exponent. Try again.");
            return CHECK_EXP_ERROR;
        default:
            puts("Unknown error. Try again.");
            return UNKNOWN;
    }  
    if (parse_number(str, &num2))
    {
        puts("Parsing failed. Try again");
        return FAILURE;
    }

    //compute
    
    return SUCCESS;
}