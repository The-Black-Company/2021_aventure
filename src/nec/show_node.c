#include "inc.h"

void show_node(t_bunny_pixelarray *px,
               t_graph *gr)
{
    size_t i;
    t_content *nc;

    for (i = 0; i < gr->node_nbr; i = i + 1)
    {
        nc = gr->nodes[i]->data;
        if (nc->state == ACT_CLEAR)
            adv_set_ellipse(px, nc->pos, nc->radius, adv_color(128, 0, 0, 0));
        else if (nc->state == ACT_WAS_PLAYER)
            adv_set_ellipse(px, nc->pos, nc->radius, adv_color(128, 0, 0, 255));
        else
            adv_set_ellipse(px, nc->pos, nc->radius, adv_color(128, 255, 0, 0));
    }
}
