#ifndef MULTIPLY_H
#define MULTIPLY_H

#include "number.h"

void multiply_mant(number_t *num1, number_t *num2, int arr0[]);
void num_carry(size_t len_m, size_t i, int arr0[]);

#endif