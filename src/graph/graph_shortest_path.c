#include "inc.h"

bool graph_path_conv(t_node *start,
                     t_node *end,
                     int nbr)
{
    size_t i;

    if (start == end)
    {
        start->step = -2;
        return (true);
    }
    for (i = 0; start->nodes[i] != NULL; i = i + 1)
    {
        if (start->nodes[i]->step == nbr + 1)
        {
            if (graph_path_conv(start->nodes[i], end, nbr + 1) == true)
            {
                start->step = -2;
                return (true);
            }
        }
    }
    return (false);
}

bool graph_path_step(t_node *start,
                     t_node *end,
                     int nbr)
{
    size_t i;
    bool temp;

    temp = false;
    if (start->step == -1 || start->step > nbr)
        start->step = nbr;
    else
        return (false);
    if (start == end)
        return (true);
    for (i = 0; start->nodes[i] != NULL; i = i + 1)
        if (graph_path_step(start->nodes[i], end, nbr + 1) == true)
            temp = true;
    return (temp);
}

void graph_shortest_path(t_graph *gr,
                         const char *start_node,
                         const char *end_node)
{
    t_node *start;
    t_node *end;

    end = graph_get(gr, end_node);
    start = graph_get(gr, start_node);
    graph_path_step(start, end, 0);
    graph_path_conv(start, end, 0);
}
