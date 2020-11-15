#include "matrix_process.h"

void convert_to_sparse(matrix_s *m, sparse_s *s)
{
    s->n_count = non_zero_count(m);
    s->c_count = m->cols;
}

stype_t non_zero_count(matrix_s *m)
{
    stype_t count = 0;
    for (stype_t j = 0; j < m->cols; j++)
        for (stype_t i = 0; i < m->rows; i++)
            if (m->matrix[j][i] != 0)
                count++;
    return count;
}
