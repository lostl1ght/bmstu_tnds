#define _USEMINGW_ANSI_STDIO 1
#include <stdio.h>
#include "number.h"
#include "inpt_oupt.h"
#include "parse.h"
#include "checking.h"
#include "multiply.h"

#define SUCCESS 0
#define FAILURE 1
#define UNKNOWN -1

int switch_func(int rc);

int main(void)
{
    char str[LEN];
    int rc;
    number_t num1 = {.len_m = 0, .mantissa = {0}, .exponent = 0};
    number_t num2 = {.len_m = 0, .mantissa = {0}, .exponent = 0};
    number_t res;
    if (input_str(str))
    {
        puts("Cannot read number. Try again.");
        return FAILURE;
    }
    rc = switch_func(check_str(str));
    if (rc)
        return rc;
     
    if (parse_number(str, &num1))
    {
        puts("Parsing failed. Try again");
        return FAILURE;
    }

    // output_check(&num1);
    // return 0;

    if (input_str(str))
    {
        puts("Cannot read number. Try again.");
        return FAILURE;
    }
    rc = switch_func(check_str(str));
    if (rc)
        return rc;
      
    if (parse_number(str, &num2))
    {
        puts("Parsing failed. Try again");
        return FAILURE;
    }
    
    if (multiply(&num1, &num2, &res))
    {    
        puts("Exponent oveflow while multiplying.");
        return FAILURE;
    }

    output_num(&res);
    
    return SUCCESS;
}

int switch_func(int rc)
{
    switch (rc)
    {
        case CHECK_SUCCESS:
            break;
        case CHECK_WRONG_CHARACTERS:
            puts("Invalid characters input. Try again.");
            break;
        case CHECK_MANT_ERROR:
            puts("Invalid characters in mantissa OR it is too long. Try again.");
            break;
        case CHECK_EXP_ERROR:
            puts("Invalid characters in exponent OR it is too long. Try again.");
            break;
        default:
            puts("Unknown error. Try again.");
            break;
    }
    return rc;
}
