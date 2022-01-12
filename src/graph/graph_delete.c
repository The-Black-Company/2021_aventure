#include "inc.h"

void graph_delete(t_graph *gr)
{
	size_t i;

	i = 0;
	while (gr->nodes[i] != NULL)
	{
		free(gr->nodes[i]->data);
		free(gr->nodes[i]->key);
		free(gr->nodes[i]->nodes);
		free(gr->nodes[i]);
		i = i + 1;
	}
	free(gr->nodes);
	free(gr);
}
