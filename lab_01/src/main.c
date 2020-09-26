#define _USEMINGW_ANSI_STDIO 1
#include <stdio.h>
#include "../inc/number.h"
#include "../inc/io.h"
#include "../inc/parse.h"
#include "../inc/check.h"

int main(void)
{
    char str[LEN];
    number_t num1 = {.len_m = 0, .mantissa = {0}, .exponent = 0};
    // number_t num2 = {.len_m = 0, .mantissa = {0}, .exponent = 0};
    // number_t res;
    if (input_str(str))
        puts("Cannot read number.");
    if (check_str(str))
        puts("Checking failed.");
    parse_number(str, &num1);
    puts("OK");
    return 0;
}