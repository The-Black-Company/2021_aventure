#include "inc.h"

t_bunny_response mouse_click(t_bunny_event_state state,
                             t_bunny_mouse_button button,
                             void *d)
{
    t_bunny_position *mouse;
    t_main_data *data;
    size_t i;
    size_t j;
    t_content *nc;

    data = d;
    if (state == GO_UP)
        return (GO_ON);
    else if (button == BMB_LEFT && data->selec != 2 && data->game->state == GAM_PROGRESS && state == GO_DOWN)
    {
        mouse = (t_bunny_position *)bunny_get_mouse_position();
        for (i = 0; i < data->game->scenes[data->game->current_scene]->gr->node_nbr; i = i + 1)
        {
            nc = data->game->scenes[data->game->current_scene]->gr->nodes[i]->data;
            if ((((adv_pow(mouse->x - nc->pos.x, 2) / (double)adv_pow(nc->radius.x, 2))) + ((adv_pow(mouse->y - nc->pos.y, 2) / (double)adv_pow(nc->radius.y, 2)))) <= 1)
            {
                for (j = 0; j < data->game->scenes[data->game->current_scene]->gr->node_nbr; j = j + 1)
                {
                    nc = data->game->scenes[data->game->current_scene]->gr->nodes[j]->data;
                    if (nc->state == ACT_PLAYER)
                    {
                        data->selec = 2;
                        nc->state = ACT_WAS_PLAYER;
                    }
                    else
                        nc->state = ACT_CLEAR;
                }
                nc = data->game->scenes[data->game->current_scene]->gr->nodes[i]->data;
                if (nc->state == ACT_WAS_PLAYER)
                {
                    nc->state = ACT_PLAYER;
                    data->selec = 1;
                    return (GO_ON);
                }
                nc->state = ACT_PLAYER;
                data->start_time = bunny_get_current_time();
                graph_path_reset(data->game->scenes[data->game->current_scene]->gr);
                data->total_time = graph_path_finder(data, data->game->scenes[data->game->current_scene]->gr);
                return (GO_ON);
            }
        }
    }
    return (GO_ON);
}
