#include "graph.h"

adjmatr_t *create_adjmatr(int size)
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
    for (int i = 0; i < m->sz; i++)
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
        for (int i = 0; i < m->sz; i++)
            free(m->m[i]);
        free(m->m);
        free(m);
    }
}

int input_adjmatr(adjmatr_t *m)
{
    while (1)
    {
        int i, j;
        if (scanf("%d", &i) != 1)
        {
            puts("Worng number.");
            return NUM_ERR;
        }
        else if (i == -1)
        {
            puts("Done.");
            return OK;
        }
        else if (i < 0 || i > m->sz - 1)
        {
            puts("Worng number.");
            return NUM_ERR;
        }

        if (scanf("%d", &j) != 1 || j < 0 || j > m->sz - 1)
        {
            puts("Worng number.");
            return NUM_ERR;
        }
        m->m[i][j] = 1;
        m->m[j][i] = 1;
    }
}

void output_adjmatr(adjmatr_t *m)
{
    for (int i = 0 ; i < m->sz; i++)
    {        
        for (int j = 0 ; j < m->sz; j++)
            printf("%d ", m->m[i][j]);
        puts("");
    }
}
