#ifndef MATRIX_PROCESS_H
#define MATRIX_PROCESS_H

#include "matrix.h"
#include "sparse.h"

void convert_to_sparse(matrix_s *m, sparse_s *s);
stype_t non_zero_count(matrix_s *m);

#endif