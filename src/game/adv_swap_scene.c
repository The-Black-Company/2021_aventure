#include "inc.h"

void adv_swap_scene(t_main_data *data)
{
    bool pass;
    t_object obj;
    size_t i;
    size_t scene;

    obj = graph_get_condition(data);
    pass = false;
    if (obj == OBJ_NONE)
        pass = true;
    for (i = 0; i < data->game->player.inventory.nbr_obj && pass == false; i = i + 1)
    {
        if (data->game->player.inventory.objs[i] == obj)
            pass = true;
    }
    if (pass == true)
    {
        scene = graph_get_scene(data);
        if (scene != 200 && scene != 300)
            data->game->current_scene = graph_get_scene(data);
        else if(scene == 200)
            data->game->state = GAM_END;
	else
            data->game->state = GAM_SECRET;
    }
}
