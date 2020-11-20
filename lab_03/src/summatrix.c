#include "summatrix.h"

void summatrix(matrix_s *const m1, matrix_s *const m2, matrix_s *const res)
{
    for (stype_t j = 0; j < res->cols; j++)
        for (stype_t i = 0; i < res->rows; i++)
            res->matrix[j][i] = m1->matrix[j][i] + m2->matrix[j][i];
}
