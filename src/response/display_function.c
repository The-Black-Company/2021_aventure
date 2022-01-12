#include "inc.h"

t_bunny_response display_function(void *d)
{
    t_main_data *data = (t_main_data *)d;
    t_word_data wd;
    t_bunny_position pos = {data->screen_size.x / 2, data->screen_size.y / 2};;

    if (data->game->state == GAM_PROGRESS)
    {
        data->game->pause_bool = false;
        // GRAPHS
        adv_fill(data->px, BLACK);
        adv_blit_img(data->px, data->game->scenes[data->game->current_scene]->background, NULL);

        data->font->clipable.scale.x = 6;
        data->font->clipable.scale.y = 6;
	wd.pos.x = data->screen_size.x / 2;
        wd.pos.y = 30;
        adv_place_text(wd.mots, (char *)data->game->scenes[data->game->current_scene]->name);
        wd.positionnement = center;
        adv_text_color(data->font, adv_color(255, 0, 0, 0));
        adv_phrase_a(data->px, data->font, wd);

        data->font->clipable.scale.x = 2.7;
        data->font->clipable.scale.y = 2.7;

        t_bunny_position intpos[2];
        intpos[0].x = 0;
        intpos[1].x = data->screen_size.x - 1;
        intpos[0].y = 3 * (data->screen_size.y / 4);
        intpos[1].y = data->screen_size.y - 1;
        adv_set_square(data->px, intpos, adv_color(255, 0, 0, 0));
        if (data->selec == 2)
        {
            data->b[0]->isClick = false;
            data->b[1]->isClick = false;
            double time = (bunny_get_current_time() - data->start_time) / data->total_time;
            if (time <= 1)
                adv_dot(data, time);
            if (time >= 1)
                adv_player_clean(data);
        }
        else
        {
            data->b[0]->isClick = true;
            data->b[1]->isClick = true;
            adv_move_player(data->px, data->game->player.sprites, graph_get_player(data->game->scenes[data->game->current_scene]->gr), 2);
        }

        //INVENTORY
        adv_show_inventory(data);

        // BUTTONS
        const t_bunny_position *mpos;
        mpos = bunny_get_mouse_position();
        // Button 0 ==> Scene SWAP 
        if (b_test(data->b[0], mpos[0]) == true && data->b[0]->isClick == true)
        {
            button_color(data->b[0], adv_color(255, 255, 255, 255));
            if (data->b[0]->fun != NULL)
                data->b[0]->fun(data);
        }
        else
	    button_color(data->b[0], adv_color(255, 102, 102, 255));

        // Button 1 ==> Recup un object
        if (b_test(data->b[1], mpos[0]) == true && data->b[1]->isClick == true)
        {
            button_color(data->b[1], adv_color(255, 255, 255, 255));
            if (data->b[1]->fun != NULL)
                data->b[1]->fun(data);
        }
        else
            button_color(data->b[1], adv_color(255, 102, 255, 178));

        wd.pos = data->b[0]->data.pos;
        wd.pos.y += data->font->clipable.buffer.height * data->font->clipable.scale.y + 20;
        adv_place_text(wd.mots, "Interact");
        wd.positionnement = center;
        adv_text_color(data->font, adv_color(255, 102, 102, 255));
        adv_phrase_a(data->px, data->font, wd);
        adv_draw_button(data->px, data->b[0]);

        wd.pos = data->b[1]->data.pos;
        wd.pos.y += data->font->clipable.buffer.height * data->font->clipable.scale.y + 20;
        adv_place_text(wd.mots, "Pick up");
        wd.positionnement = center;
        adv_text_color(data->font, adv_color(255, 102, 255, 178));
        adv_phrase_a(data->px, data->font, wd);
        adv_draw_button(data->px, data->b[1]);

	// DEBUG
	if (data->debug)
	{
	    show_link(data->px, data->game->scenes[data->game->current_scene]->gr);
	    show_node(data->px, data->game->scenes[data->game->current_scene]->gr);
	}

    }
    else if (data->game->state == GAM_PAUSE)
    {
        if(data->game->pause_bool == false)
	{
	    data->game->pause_bool = true;
	    adv_fill_transp(data->px, adv_color(100, 0, 0, 0));
	}
        data->font->clipable.scale.x = 5.7;
        data->font->clipable.scale.y = 5.7;
        wd.pos = pos;
        adv_place_text(wd.mots, "Pause");
        wd.positionnement = center;
        adv_text_color(data->font, adv_color(255, rand() % 255, rand() % 255, rand() % 255));
        adv_phrase_a(data->px, data->font, wd);
    }
    else if (data->game->state == GAM_END)
    {
        adv_fill(data->px, adv_color(255, 153, 255, 153));
        data->font->clipable.scale.x = 5.7;
        data->font->clipable.scale.y = 5.7;
        wd.pos = pos;
        adv_place_text(wd.mots, "You Won !!");
        wd.positionnement = center;
        adv_text_color(data->font, adv_color(255, 255, 255, 51));
        adv_phrase_a(data->px, data->font, wd);
    }
    else if (data->game->state == GAM_SECRET)
    {
        adv_fill_transp(data->px, adv_color(5, 0, 0, 0));
        data->font->clipable.scale.x = 5.7;
        data->font->clipable.scale.y = 5.7;
        wd.pos = pos;
        adv_place_text(wd.mots, "It's Dangerous to go alone");
        wd.positionnement = center;
        adv_text_color(data->font, adv_color(255, rand() % 255, rand() % 255, rand() % 255));
        adv_phrase_a(data->px, data->font, wd);
    }

    bunny_blit(&data->win->buffer, &data->px->clipable, NULL);
    bunny_display(data->win);
    return (GO_ON);
}
