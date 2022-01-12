#include "inc.h"

void adv_show_inventory(t_main_data *data)
{
    t_word_data wd;
    size_t i;

    wd.pos.y = (3 * (data->screen_size.y / 4)) + 50;
    wd.pos.x = data->screen_size.x / 2;
    wd.positionnement = center;
    data->font->clipable.scale.x = 2;
    data->font->clipable.scale.y = 2;
    adv_text_color(data->font, adv_color(255, 255, 255, 102));
    for (i = 0; i < data->game->player.inventory.nbr_obj; i = i + 1)
    {
        if (data->game->player.inventory.objs[i] == OBJ_KEY_1)
            adv_place_text(wd.mots, "HOME KEY");
        else if (data->game->player.inventory.objs[i] == OBJ_KEY_2)
            adv_place_text(wd.mots, "BEDROOM KEY");
        else if (data->game->player.inventory.objs[i] == OBJ_KEY_3)
            adv_place_text(wd.mots, "GAMEPAD");
        adv_phrase_a(data->px, data->font, wd);
        wd.pos.y = wd.pos.y + 65;
    }
}
