#include "inc.h"

t_bunny_response key_event_response(t_bunny_event_state state,
                                    t_bunny_keysym keycode,
                                    void *d)
{
    t_main_data *data = (t_main_data *)d;
    if (state == GO_DOWN && keycode == BKS_ESCAPE)
        return (EXIT_ON_SUCCESS);
    if (state == GO_DOWN && keycode == BKS_SPACE)
    {
        if (data->game->state == GAM_PROGRESS)
            data->game->state = GAM_PAUSE;
        else if (data->game->state == GAM_PAUSE)
            data->game->state = GAM_PROGRESS;
    }
    if (state == GO_DOWN && keycode == BKS_D)
    {
        if (data->debug == false)
            data->debug = true;
        else if (data->debug == true)
            data->debug = false;
    }
    return (GO_ON);
}
