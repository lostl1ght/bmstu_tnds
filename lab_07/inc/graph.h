#ifndef GRAPH_H
#define GRAPH_H

#include <stdlib.h>

typedef struct
{
    size_t sz;
    int **m;
} adjmatr_t;

adjmatr_t *create_adjmatr(size_t size);
void delete_adjmatr(adjmatr_t *m);

#endif