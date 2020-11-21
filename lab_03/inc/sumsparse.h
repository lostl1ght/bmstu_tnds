#ifndef SUMSPARSE_H
#define SUMSPARSE_H

#include <stdlib.h>
#include <string.h>
#include "sparse.h"

// #define SUMOK 0
// #define SUMEMEM 1

void sumsparse(sparse_s *const s1, sparse_s *const s2, sparse_s *const res);
stype_t count(mtype_t *swtch, stype_t size);

#endif
