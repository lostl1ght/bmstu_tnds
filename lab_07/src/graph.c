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
    for (int i = 0; i < m->sz; i++)
    {
        for (int j = 0; j < m->sz; j++)
            printf("%d ", m->m[i][j]);
        puts("");
    }
}

void export_graph(adjmatr_t m, int is_conn)
{
    FILE *export = fopen("graph.txt", "w");
    fprintf(export, "graph {\n");
    fprintf(export, "label = \"%s\";\n", (is_conn ? "Connected": "Not connected"));
    fprintf(export, "labelloc = \"t\";\n");

    for (int i = 0; i < m.sz; ++i)
        for (int j = 0; j < m.sz; ++j)
            if (m.m[i][j])
                m.m[j][i] = 0;

    for (int i = 0; i < m.sz; ++i)
    {
        for (int j = 0; j < m.sz; ++j)
            if (m.m[i][j])
                fprintf(export, "%d -- %d;\n", i, j);
        fprintf(export, "%d;\n", i);
    }

    fprintf(export, "}\n");
    fclose(export);

    system("dot -Tpng graph.txt -o graph.png");
    system("eog graph.png");
}

int is_connected(const adjmatr_t *m)
{
    int visited[m->sz];
    for (int i = 1; i < m->sz; i++)
        visited[i] = 0;
    int visited_ver = dfs_adjmatr(m, visited, 0);
    return visited_ver == m->sz;
}

int dfs_adjmatr(const adjmatr_t *m, int *visited, int ver)
{
    int visited_ver = 1;
    visited[ver] = 1;
    for (int i = 0; i < m->sz; i++)
        if (m->m[ver][i] && !visited[i])
            visited_ver += dfs_adjmatr(m, visited, i);
    return visited_ver;
}
