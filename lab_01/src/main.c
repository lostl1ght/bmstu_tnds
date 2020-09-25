#define _USEMINGW_ANSI_STDIO 1
#include "../inc/io.h"
#include "../inc/parse.h"
#include "../inc/check.h"

int main(void)
{
    char str[MAX_SYMBOLS + 2]; // 38 symbols + \n + \0
    number_t num1 = {.len_m = 0, .mantissa = {0}, .exponent = 0};
    // number_t num2 = {.len_m = 0, .mantissa = {0}, .exponent = 0};
    // number_t res;
    input_str(str);
    check_str(str);
    parse_number(str, &num1);
    return 0;
}