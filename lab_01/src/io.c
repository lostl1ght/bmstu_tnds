#include "../inc/io.h"

#define IO_SUCCESS 0
#define IO_FAILURE 1

int input_str(char str[])
{
    char c;
    printf("Input number: ");
    while ((c = getchar()) == '0')
        ;
    str[0] = c;
    if (!fgets(str + 1, LEN - 1, stdin))
        return IO_FAILURE;
    return IO_SUCCESS;
}

void output_check(const number_t *num)
{
    printf("Sign is %d\n", num->sign_m);
    printf("Mantissa is ");
    for (size_t i = num->len_m - 1; i != 0; i--)
        printf("%d", num->mantissa[i]);
    printf("%d", num->mantissa[0]);
    printf("\nExponent is %d", num->exponent);
}
