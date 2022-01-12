#include "inc.h"

void graph_link(t_graph *gr,
				const char *src_node,
				const char *target_node,
				double time)
{
	size_t i;
	t_node *src;
	t_node *target;

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
	src->nodes = adv_realloc(src->nodes, sizeof(t_node *) * (i + 1), sizeof(t_node *) * (i + 2));
	src->time = adv_realloc(src->time, sizeof(double) * (i + 1), sizeof(double) * (i + 2));
	src->nodes[i] = target;
	src->nodes[i + 1] = NULL;
	src->time[i] = time;
	src->time[i + 1] = 0;
}
