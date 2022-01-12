#include "inc.h"

void show_link(t_bunny_pixelarray *px,
			   t_graph *gr)
{
	size_t i;
	size_t j;
	unsigned int colors;
	t_content *nc;
	t_bunny_position pos[2];

	for (i = 0; i < gr->node_nbr; i = i + 1)
	{
		nc = gr->nodes[i]->data;
		pos[0].x = nc->pos.x;
		pos[0].y = nc->pos.y;
		colors = WHITE;
		for (j = 0; gr->nodes[i]->nodes[j] != NULL; j = j + 1)
		{
			nc = gr->nodes[i]->nodes[j]->data;
			pos[1].x = nc->pos.x;
			pos[1].y = nc->pos.y;
			adv_set_line(px, pos, colors);
		}
	}
}
