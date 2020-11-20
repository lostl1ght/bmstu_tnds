#ifndef SPARSE_H
#define SPARSE_H

#include <stdio.h>
#include <stdlib.h>
#include "mtypes.h"

#define SOK 0
#define SEREAD 1
#define SEMEM 2

typedef struct sparse
{
    mtype_t *non_zero;
    mtype_t *rows;
    stype_t n_count;
    mtype_t *col;
    stype_t c_count;
    stype_t r_count;
} sparse_s;

int create_sparse(sparse_s *const s);
void delete_sparse(sparse_s *const s);
int input_sparse(sparse_s *const s);
void output_sparse(sparse_s *const s);
int sparse_input_wrapper(sparse_s *const s);

#endif
