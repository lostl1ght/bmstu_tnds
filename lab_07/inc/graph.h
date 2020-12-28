#ifndef GRAPH_H
#define GRAPH_H

#include <stdio.h>
#include <stdlib.h>
#include "returns.h"

typedef struct
{
    int sz;
    int **m;
} adjmatr_t;

adjmatr_t *create_adjmatr(int size);
void delete_adjmatr(adjmatr_t *m);

int input_adjmatr(adjmatr_t *m);
void output_adjmatr(adjmatr_t *m);

void export_graph(adjmatr_t m, int is_conn);

int is_connected(const adjmatr_t *m);
int dfs_adjmatr(const adjmatr_t *m, int *visited, int ver);

#endif