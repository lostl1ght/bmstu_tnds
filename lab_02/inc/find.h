#ifndef FIND_H
#define FIND_H

#include "flat.h"

int find_in_file(FILE *f_in, FILE *f_out);
int get_ind(flat_t *flats, int *ind, int count, int min, int max);

#endif