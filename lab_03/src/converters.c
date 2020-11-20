#include "converters.h"

int convert_to_sparse(matrix_s *m, sparse_s *s)
{
    int found;
    stype_t len = 0;
    s->n_count = non_zero_count(m);
    s->c_count = m->cols;
    s->r_count = m->rows;
    if (create_sparse(s))
        return PEMEM;
    for (stype_t j = 0; j < m->cols; j++)
    {
        found = 0;
        for (stype_t i = 0; i < m->rows; i++)
            if (m->matrix[j][i] != 0)
            {
                s->non_zero[len] = m->matrix[j][i];
                s->rows[len] = i;
                if (!found)
                {
                    s->col[j] = len;
                    found = 1;
                }
                len++;
            }
        if (!found)
            s->col[j] = len;
    }
    s->col[m->cols] = s->n_count;
    return POK;
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

int convert_to_matrix(matrix_s *m, sparse_s *s)
{
    m->cols = s->c_count;
    m->rows = s->r_count;
    if (create_matrix(m))
        return PEMEM;
    for (stype_t j = 0; j < m->cols; j++)
    {
        for (stype_t i = s->col[j]; i < s->col[j + 1]; i++)
            m->matrix[j][s->rows[i]] = s->non_zero[i];
    }
    return POK;
}
