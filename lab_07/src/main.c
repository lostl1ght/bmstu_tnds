#include <stdio.h>
#include "returns.h"
#include "graph.h"

int main(void)
{
    puts("This program enables to find out if a graph is connected.");

    puts("Enter veterx number: ");
    long size;
    if (scanf("%ld", &size) != 1 || size < 1)
    {
        puts("Wrong number.");
        return NUM_ERR;
    }
    adjmatr_t *graph;
    if (!(graph = create_adjmatr(size)))
    {
        puts("Couldn't create adjacency matrix.");
        return MEM_ERR;
    }

    puts("Enter arcs (format: \"v_1 v_2\"). Enter -1 to stop:");
    if (input_adjmatr(graph))
        return NUM_ERR;

    puts("Adjacency matrix:");
    output_adjmatr(graph);

    return 0;
}
