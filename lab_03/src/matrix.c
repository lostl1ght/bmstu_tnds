#include "matrix.h"

int create_matrix(matrix_s *const m)
{
    m->matrix = calloc(m->cols, sizeof(mtype_t *));
    if (!m)
        return MEMEM;
    for (stype_t j = 0; j < m->cols; j++)
        if (!(m->matrix[j] = malloc(m->rows * sizeof(mtype_t))))
            return MEMEM;
    return OK;
}

void delete_matrix(matrix_s *const m)
{
    for (stype_t j = 0; j < m->cols; j++)
        free(m->matrix[j]);
    free(m->matrix);
}

int input_matrix(matrix_s *const m)
{
    char buf[1024];
    for (stype_t i = 0; i < m->rows; i++)
        for (stype_t j = 0; j < m->cols; j++)
            if (scanf(TYPESPEC, &m->matrix[j][i]) != 1)
            {
                fgets(buf, 1024, stdin);
                return MEREAD;
            }
    return OK;
}

void output_matrix(matrix_s *const m)
{
    for (stype_t i = 0; i < m->rows; i++)
    {
        for (stype_t j = 0; j < m->cols; j++)
            printf(OUTSPEC, m->matrix[j][i]);
        puts("");
    }
}

int read_size(matrix_s *const m)
{
    char buf[1024];
    printf("Enter row count: ");
    if (scanf(TYPESPEC, &m->rows) != 1 || m->rows < 1)
    {
        fgets(buf, 1024, stdin);
        return MEREAD;
    }
    printf("Enter column count: ");
    if (scanf(TYPESPEC, &m->cols) != 1 || m->cols < 1)
    {
        fgets(buf, 1024, stdin);
        return MEREAD;
    }
    puts("");
    return OK;
}
