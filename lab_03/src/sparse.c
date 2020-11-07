#include "sparse.h"

int sparse_create(sparse_s *const s)
{
    s->non_zero = malloc(s->n_count * sizeof(mtype_t));
    if (!s->non_zero)
        return SEMEM;
    s->rows = malloc(s->n_count * sizeof(mtype_t));
    if (!s->rows)
        return SEMEM;
    s->col = malloc(s->c_count * sizeof(mtype_t));
    if (!s->col)
        return SEMEM;
    return SOK;
}

void sparse_delete(sparse_s *const s)
{
    free(s->non_zero);
    free(s->rows);
    free(s->col);
}

int sparse_input(sparse_s *const s)
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
}

void sparse_output(sparse_s *const s)
{
    puts("Non zero elements:");
    for (stype_t i = 0; i < s->n_count; i++)
        printf(OUTSPEC, s->non_zero[i]);
    puts("Non zero element row numbers:");
    for (stype_t i = 0; i < s->n_count; i++)
        printf(OUTSPEC, s->rows + i);
    puts("Column starting index of non zero elements:");
    for (stype_t i = 0; i < s->c_count; i++)
        printf(OUTSPEC, s->col + i);
}
