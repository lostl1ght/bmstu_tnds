#define _USEMINGW_ANSI_STDIO 1
#include "../inc/io.h"
#include "../inc/parse.h"

int main(void)
{
    char str[MAX_SYMBOLS + 1];
    number_t num1 = {.len_m = 0, .mantissa = {0}};
    input_str(str);
    parse_number(str, &num1);
    return 0;
}