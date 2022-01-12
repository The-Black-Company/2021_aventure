#include "inc.h"

void graph_path_reset(t_graph *gr)
{
    size_t i;

    for (i = 0; gr->nodes[i] != NULL; i = i + 1)
        gr->nodes[i]->step = -1;
}