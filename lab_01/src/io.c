#include "../inc/io.h"

#define IO_SUCCESS 0
#define IO_FAILURE 1

#define IO_WRONG_CHARACTERS 2

int input_str(char str[])
{
    printf("Input number: ");
    if (!fgets(str, LEN, stdin))
        return IO_FAILURE;
    return IO_SUCCESS;
}

void output_check(const number_t *num)
{
    printf("Sign is %d\n", num->sign_m);
    printf("Mantissa is ");
    for (size_t i = num->len_m - 1; i != 0 ; i--)
        printf("%d", num->mantissa[i]);
    printf("%d", num->mantissa[0]);
    printf("\nExponent is %d", num->exponent);
}
