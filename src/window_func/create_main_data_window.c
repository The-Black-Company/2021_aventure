#include "inc.h"

void create_main_data_window(t_main_data *data,
                             char *name)
{
    const t_bunny_size *screen = bunny_get_screen_resolution();

    data->screen_size.x = screen->x;
    data->screen_size.y = screen->y;
    data->win = bunny_start(screen->x, screen->y, true, name);
    data->px = bunny_new_pixelarray(data->win->buffer.width, data->win->buffer.height);
    adv_fill(data->px, BLACK);
}
