#include "inc.h"

void graph_get_selectors(t_graph *gr,
                         t_node **start,
                         t_node **end)
{
    size_t i;
    t_content *content;

    for (i = 0; i < gr->node_nbr; i = i + 1)
    {
        content = gr->nodes[i]->data;
        if (content->state == ACT_PLAYER)
            *end = gr->nodes[i];
        else if (content->state == ACT_WAS_PLAYER)
            *start = gr->nodes[i];
    }
}

t_node *adv_set_value(t_node *start)
{
    start->step = start->step - 1;
    return (start);
}

double graph_timer(t_node *start,
                   t_node *end)
{
    size_t i;
    t_node *temp;
    double time;
    bool went;

    time = 0;
    while (start != end)
    {
        temp = adv_set_value(start);
        went = false;
        for (i = 0; start->nodes[i] != NULL && temp == start; i = i + 1)
        {
            if (start->nodes[i]->step == -2)
            {
                time = start->time[i] + time;
                start = start->nodes[i];
                went = true;
            }
        }
        if (went == false)
            return (time);
    }
    return (time);
}

double graph_path_finder(t_main_data *data,
                         t_graph *gr)
{
    t_node *nodes[2];
    double time;

    if (data->selec == 2)
    {
        graph_get_selectors(gr, &nodes[0], &nodes[1]);
        graph_shortest_path(gr, nodes[0]->key, nodes[1]->key);
        time = graph_timer(nodes[0], nodes[1]);
    }
    graph_path_reset(gr);
    return (time);
}