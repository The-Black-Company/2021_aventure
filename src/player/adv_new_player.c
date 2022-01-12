#include "inc.h"

t_player adv_new_player(const char *path)
{
    t_player play;
    play.sprites = bunny_load_pixelarray(path);
    play.inventory.nbr_obj = 0;
    play.inventory.objs = malloc(sizeof(t_object));

    play.sprites->clipable.clip_width = play.sprites->clipable.buffer.width / 5;
    play.sprites->clipable.clip_height = play.sprites->clipable.buffer.height / 3;

    return play;
}