#include "inc.h"

void graph_unlink(t_graph *gr,
				  const char *src_node,
				  const char *target_node)
{
	size_t i;
	size_t j;
	t_node *src;
	t_node *target;
	t_node **news;

	src = NULL;
	target = NULL;
	for (i = 0; gr->nodes[i] != NULL && (target == NULL || src == NULL); i = i + 1)
	{
		if (adv_strcmp(gr->nodes[i]->key, src_node) == 0)
			src = gr->nodes[i];
		if (adv_strcmp(gr->nodes[i]->key, target_node) == 0)
			target = gr->nodes[i];
	}
	for (i = 0; src->nodes[i] != NULL; i = i + 1)
		;
	news = malloc(sizeof(t_node *) * i);
	i = 0;
	j = 0;
	for (i = 0; src->nodes[i] != NULL; i = i + 1)
	{
		if (src->nodes[i] != target)
		{
			news[j] = src->nodes[i];
			j = j + 1;
		}
	}
	news[j] = NULL;
	free(src->nodes);
	src->nodes = news;
}
