#ifndef MATRIX_H
#define MATRIX_H

#include <stdio.h>
#include <stdlib.h>

#define TYPESPEC "%ld"
#define OUTSPEC "%5ld"

#define OK 0
#define MEREAD 1
#define MEMEM 2

typedef long mtype_t;
typedef long stype_t;

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