#include "inc.h"

size_t graph_pop_size(t_node *node)
{
	size_t i;

	i = 0;
	while (node->nodes[i] != NULL)
		i = i + 1;
	return (i);
}

void graph_pop_linkclear(t_graph *gr,
						 t_node *node)
{
	t_node **new;
	size_t i;
	size_t k;
	size_t j;
	size_t l;

	for (i = 0; gr->nodes[i] != NULL; i = i + 1)
	{
		for (j = 0; gr->nodes[i]->nodes[j] != NULL; j = j + 1)
		{
			if (gr->nodes[i]->nodes[j] == node)
			{
				new = malloc(sizeof(t_node *) * (graph_pop_size(gr->nodes[i])));
				k = 0;
				for (l = 0; gr->nodes[i]->nodes[l] != NULL; l = l + 1)
				{
					if (l != j)
					{
						new[k] = gr->nodes[i]->nodes[l];
						k = k + 1;
					}
				}
				new[k] = NULL;
				free(gr->nodes[i]->nodes);
				gr->nodes[i]->nodes = new;
			}
		}
	}
}

void graph_pop(t_graph *gr,
			   const char *key)
{
	t_node *node;
	t_node **new;
	size_t i;
	size_t j;
	size_t k;

	for (k = 0; gr->nodes[k] != NULL && adv_strcmp(gr->nodes[k]->key, key) != 0; k = k + 1)
		;
	node = gr->nodes[k];
	new = malloc(sizeof(t_node *) * gr->node_nbr);
	j = 0;
	for (i = 0; gr->nodes[i] != NULL; i = i + 1)
	{
		if (i != k)
		{
			new[j] = gr->nodes[i];
			j = j + 1;
		}
	}
	new[j] = NULL;
	free(gr->nodes);
	gr->nodes = new;
	graph_pop_linkclear(gr, node);
	free(node->key);
	free(node->data);
	free(node->nodes);
	free(node);
	gr->node_nbr = gr->node_nbr - 1;
}
