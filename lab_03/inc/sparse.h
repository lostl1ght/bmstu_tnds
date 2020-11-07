#ifndef SPARSE_H
#define SPARSE_H

#include <stdio.h>
#include <stdlib.h>
#include "m_types.h"

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
} sparse_s;

int sparse_create(sparse_s *const s);
void sparse_delete(sparse_s *const s);
int sparse_input(sparse_s *const s);
void sparse_output(sparse_s *const s);

#endif
