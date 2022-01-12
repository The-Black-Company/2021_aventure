#include "inc.h"

void adv_player_clean(t_main_data *data)
{
    size_t i;
    t_content *content;

    data->selec = 1;
    for (i = 0; i < data->game->scenes[data->game->current_scene]->gr->node_nbr; i = i + 1)
    {
        content = data->game->scenes[data->game->current_scene]->gr->nodes[i]->data;
        if (content->state == ACT_WAS_PLAYER)
        {
            content->state = ACT_CLEAR;
            return;
        }
    }
}