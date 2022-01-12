#include "inc.h"

t_graph *graph_new(size_t data_size)
{
	t_graph *gr;

	gr = malloc(sizeof(t_graph));
	gr->data_size = data_size;
	gr->node_nbr = 0;
	gr->nodes = malloc(sizeof(t_node *));
	gr->nodes[0] = NULL;
	return (gr);
}