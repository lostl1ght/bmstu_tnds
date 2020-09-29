#ifndef MULTIPLY_H
#define MULTIPLY_H

#include "number.h"

#define MTL_SUCCESS 0
#define MLT_FAILURE 1

int multiply(number_t *num1, number_t *num2, number_t *res);
size_t multiply_mant(number_t *num1, number_t *num2, number_t *res);
void num_carry(size_t len_m, size_t i, int arr0[]);
size_t round_mant(int arr[], size_t *old_len);

#endif