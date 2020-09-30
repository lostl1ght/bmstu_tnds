#include "multiply.h"

int multiply(number_t *num1, number_t *num2, number_t *res)
{
    size_t old_len;
    int check_exp = 1;
    old_len = multiply_mant(num1, num2, res);
    res->sign_m = num1->sign_m * num2->sign_m;
    res->exponent = num1->exponent + num2->exponent + old_len;
    for (size_t i = 0; i < MAX_EXPONENT; i++)
        check_exp *= 10;
    if (res->exponent > check_exp - 1 || res->exponent < -(check_exp - 1))
        return MLT_FAILURE;
    if (res->len_m > 0)
        while (res->mantissa[0] == 0)
        {
            for (size_t i = 0; i < res->len_m - 1; i++)
                res->mantissa[i] = res->mantissa[i + 1];
            res->len_m--;
        }
    return MTL_SUCCESS;
}

size_t multiply_mant(number_t *num1, number_t *num2, number_t *res)
{
    int arr0[MAX_MANTISSA * 2] = {0};
    int arr1[MAX_MANTISSA * 2] = {0};
    size_t old_len = 0;
    if (num2->len_m > num1->len_m)
    {
        number_t *tmp = num1;
        num1 = num2;
        num2 = tmp;
    }

    for (size_t j = 0; j < num1->len_m; j++)
        arr0[j] = num1->mantissa[j] * num2->mantissa[0];

    num_carry(num1->len_m, 0, arr0);

    for (size_t i = 1; i < num2->len_m; i++)
    {
        for (size_t j = 0; j < num1->len_m; j++)
            arr1[j + i] = num1->mantissa[j] * num2->mantissa[i];
        for (size_t j = 0; j < num1->len_m + i; j++)
            arr0[j] += arr1[j];
        for (size_t j = 0; j < num1->len_m + i; j++)
            arr1[j] = 0;

        num_carry(num1->len_m, i, arr0);
    }
    res->len_m = round_mant(arr0, &old_len);
    if (res->len_m > 0)
        for (size_t i = 0; i < res->len_m - 1; i++)
        {
            if (arr0[i] > 9)
            {
                arr0[i] %= 10; 
                arr0[i + 1] += 1;
            }
        }
    for (size_t i = 0; i < res->len_m; i++)
        res->mantissa[i] = arr0[i];
    return old_len;
}

void num_carry(size_t len_m, size_t i, int arr0[])
{
    for (size_t j = 0; j < len_m + i; j++)
    {
        arr0[j + 1] += arr0[j] / 10;
        arr0[j] %= 10;
    }
}

size_t round_mant(int arr[], size_t *old_len)
{
    size_t len = MAX_MANTISSA * 2;
    while (arr[len - 1] == 0 && len != 1)
        len--;
    if (arr[0] == 0 && len == 1)
        len--;
    *old_len = len;
    if (len > MAX_MANTISSA)
    {
        size_t reps = len - MAX_MANTISSA;
        for (size_t i = 0; i < reps; i++)
        {
            size_t j;
            if (arr[0] > 4)
                arr[1]++;
            for (j = 0; j < len - 1; j++)
                arr[j] = arr[j + 1];
            arr[j] = 0;
            len--;
        }
    }
    return len;
}