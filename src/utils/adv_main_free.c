#include "inc.h"

void adv_main_free(t_main_data data)
{
    bunny_stop(data.win);
    bunny_delete_clipable(&data.px->clipable);
    bunny_delete_clipable(&data.font->clipable);
    adv_remove_button(data.b[0]);
    adv_remove_button(data.b[1]);
    adv_delete_game(data.game);
}