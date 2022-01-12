#include "inc.h"

t_object graph_get_condition(t_main_data *data)
{
    size_t i;
    t_content *content;

    for (i = 0; i < data->game->scenes[data->game->current_scene]->gr->node_nbr; i = i + 1)
    {
        content = data->game->scenes[data->game->current_scene]->gr->nodes[i]->data;
        if (content->state == ACT_PLAYER)
            return (content->condition);
    }
    return (OBJ_NONE);
}