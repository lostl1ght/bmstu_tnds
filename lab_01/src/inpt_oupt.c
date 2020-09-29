#include "inpt_oupt.h"

#define IO_SUCCESS 0
#define IO_FAILURE 1

int input_str(char str[])
{
    char c;
    printf("Input number: ");
    while ((c = getchar()) == '0')
        ;
    if (c == '\n' || c == EOF)
    {
        str[0] = '0';
        str[1] = '\0';
    }
    else
    {
        str[0] = c;
        if (!fgets(str + 1, LEN - 1, stdin))
            return IO_FAILURE;
    }
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

void output_num(const number_t *num)
{
    puts("");
    if (num->sign_m == -1)
        printf("-");
    printf("0.");
    if (num->len_m > 0)
    {
        for (size_t i = num->len_m - 1; i != 0; i--)
            printf("%d", num->mantissa[i]);
        printf("%d", num->mantissa[0]);
        printf("e%d", num->exponent);
    }
    else
        puts("0");
}
