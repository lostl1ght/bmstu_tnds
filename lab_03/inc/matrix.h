#ifndef MATRIX_H
#define MATRIX_H

#include <stdio.h>
#include <stdlib.h>
#include "m_types.h"

#define OK 0
#define EREAD 1
#define EMEM 2

typedef struct matrix
{
    mtype_t **matrix;
    stype_t rows;
    stype_t cols;
} matrix_s;

int create_matrix(matrix_s *const m);
void delete_matrix(matrix_s *const m);
int input_matrix(matrix_s *const m);
void output_matrix(matrix_s *const m);
int read_size(matrix_s *const m);

#endif