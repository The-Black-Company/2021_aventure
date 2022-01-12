#include "inc.h"

void adv_get_object(t_main_data *data)
{
    t_object obj;
    bool pass;
    size_t i;

    pass = false;
    obj = graph_get_object(data);
    if (obj != OBJ_NONE)
    {
        if (data->game->player.inventory.nbr_obj != 0)
        {
            for (i = 0; i < data->game->player.inventory.nbr_obj && pass == false; i = i + 1)
                if (data->game->player.inventory.objs[i] == obj)
                    pass = true;
            if (pass == true)
                return;
            data->game->player.inventory.objs = adv_realloc(data->game->player.inventory.objs, sizeof(t_object) * (data->game->player.inventory.nbr_obj), sizeof(t_object) * (data->game->player.inventory.nbr_obj + 1));
        }
        data->game->player.inventory.objs[data->game->player.inventory.nbr_obj] = obj;
        data->game->player.inventory.nbr_obj = data->game->player.inventory.nbr_obj + 1;
    }
}