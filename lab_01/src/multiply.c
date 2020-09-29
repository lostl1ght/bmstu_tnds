#include "../inc/multiply.h"

void multiply_mant(number_t *num1, number_t *num2, int arr0[])
{
    int arr1[MAX_MANTISSA * 2] = {0};
    if (num2->len_m > num1->len_m)
    {
        number_t *tmp= num1;
        num1 = num2;
        num2 = tmp;
    }

    for (size_t j = 0; j < num1->len_m; j++)
        arr0[j] = num1->mantissa[j] * num2->mantissa[0];

    for (size_t j = 0; j < num1->len_m; j++)
    {
        arr0[j + 1] += arr0[j] / 10;
        arr0[j] %= 10;
    }

    for (size_t i = 1; i < num2->len_m; i++)
    {
        for (size_t j = 0; j < num1->len_m; j++)
            arr1[j + i] = num1->mantissa[j] * num2->mantissa[i];
        for (size_t j = 0; j < num1->len_m + i; j++)
            arr0[j] += arr1[j];
        for (size_t j = 0; j < num1->len_m + i; j++)
            arr1[j] = 0;
        
        for (size_t j = 0; j < num1->len_m + i; j++)
        {
            arr0[j + 1] += arr0[j] / 10;
            arr0[j] %= 10;
        }
    }
}