#include "inc.h"

t_node *graph_get(t_graph *gr,
				  const char *key)
{
	size_t i;

	i = 0;
	while (gr->nodes[i] != NULL)
	{
		if (adv_strcmp(gr->nodes[i]->key, key) == 0)
			return (gr->nodes[i]);
		i = i + 1;
	}
	return (NULL);
}
