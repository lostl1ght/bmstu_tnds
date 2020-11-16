#include "sparse.h"

int create_sparse(sparse_s *const s)
{
    s->non_zero = malloc(s->n_count * sizeof(mtype_t));
    if (!s->non_zero)
        return SEMEM;
    s->rows = malloc(s->n_count * sizeof(mtype_t));
    if (!s->rows)
    {
        free(s->non_zero);
        return SEMEM;
    }
    s->col = malloc(s->c_count * sizeof(mtype_t));
    if (!s->col)
    {
        free(s->non_zero);
        free(s->rows);
        return SEMEM;
    }
    return SOK;
}

void delete_sparse(sparse_s *const s)
{
    free(s->non_zero);
    free(s->rows);
    free(s->col);
}

int input_sparse(sparse_s *const s)
{
    puts("Enter non zero elements:");
    for (stype_t i = 0; i < s->n_count; i++)
        if (scanf(TYPESPEC, s->non_zero + i) != 1)
            return SEREAD;
    puts("Enter non zero element row numbers:");
    for (stype_t i = 0; i < s->n_count; i++)
        if (scanf(TYPESPEC, s->rows + i) != 1)
            return SEREAD;
    puts("Enter column starting index of non zero elements:");
    for (stype_t i = 0; i < s->c_count; i++)
        if (scanf(TYPESPEC, s->col + i) != 1)
            return SEREAD;
    return SOK;
}

void output_sparse(sparse_s *const s)
{
    puts("Non zero elements:");
    for (stype_t i = 0; i < s->n_count; i++)
        printf(OUTSPEC, s->non_zero[i]);
    puts("Non zero element row numbers:");
    for (stype_t i = 0; i < s->n_count; i++)
        printf(OUTSPEC, s->rows[i]);
    puts("Column starting index of non zero elements:");
    for (stype_t i = 0; i < s->c_count; i++)
        printf(OUTSPEC, s->col[i]);
}
