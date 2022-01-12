#include "inc.h"

t_node *graph_push(t_graph *gr,
                   const char *key,
                   void *data)
{
    t_node *node;

    node = malloc(sizeof(t_node));
    node->data = malloc(gr->data_size);
    adv_memcpy(node->data, data, gr->data_size);
    node->key = adv_strdup(key);
    node->nodes = malloc(sizeof(t_node *));
    node->nodes[0] = NULL;
    node->step = -1;
    node->time = malloc(sizeof(double));
    node->time[0] = 0;
    gr->nodes = adv_realloc(gr->nodes, sizeof(t_node *) * (gr->node_nbr + 1), sizeof(t_node *) * (gr->node_nbr + 2));
    gr->nodes[gr->node_nbr] = node;
    gr->nodes[gr->node_nbr + 1] = NULL;
    gr->node_nbr = gr->node_nbr + 1;
    return (node);
}