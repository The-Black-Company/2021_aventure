#include "inc.h"

t_bunny_position graph_get_player(t_graph *gr)
{
    size_t i;
    t_content *content;
    t_bunny_position err;

    err.x = -1;
    err.y = -1;
    for (i = 0; i < gr->node_nbr; i = i + 1)
    {
        content = gr->nodes[i]->data;
        if (content->state == ACT_PLAYER)
            return (content->pos);
    }
    return (err);
}