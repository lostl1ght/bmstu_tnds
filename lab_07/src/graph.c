#include "graph.h"

adjmatr_t *create_adjmatr(size_t size)
{
    adjmatr_t *m;
    if (!(m = malloc(sizeof *m)))
        return NULL;
    m->sz = size;
    if (!(m->m = calloc(size, sizeof *m->m)))
    {
        free(m);
        return NULL;
    }
    for (size_t i = 0; i < m->sz; i++)
        if (!(m->m[i] = calloc(m->sz, sizeof *m->m[i])))
        {
            delete_adjmatr(m);
            return NULL;
        }
    return m;
}

void delete_adjmatr(adjmatr_t *m)
{
    if (m)
    {
        for (size_t i = 0; i < m->sz; i++)
            free(m->m[i]);
        free(m->m);
        free(m);
    }
}
