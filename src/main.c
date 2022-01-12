#include "inc.h"

bunny_declare_context(marverscontext);

static t_bunny_anonymous_context context =
    {
        .loop = loop_function,
        .key = key_event_response,
        .display = display_function,
        .click = mouse_click,
};

int main(void)
{
    srand(time(NULL));
    t_main_data main_data;

    create_main_data_window(&main_data, WIN_NAME);
    main_data.font = bunny_load_pixelarray("res/zelda_font.png");

    t_bunny_position pos = {150, (3 * (main_data.screen_size.y / 4) + (main_data.screen_size.y / 4) / 2) - 20};
    main_data.b[0] = adv_create_button(pos, ovale);
    button_color(main_data.b[0], adv_color(255, 102, 102, 255));
    adv_set_button_size_ovale(main_data.b[0], 50, 20);

    pos.x = main_data.screen_size.x - 150;
    main_data.b[1] = adv_create_button(pos, ovale);
    button_color(main_data.b[1], adv_color(255, 102, 255, 178));
    adv_set_button_size_ovale(main_data.b[1], 50, 20);

    if((main_data.game = adv_load_game()) == NULL)
        return (-1);

    adv_set_button_fun(main_data.b[0], "adv_swap_scene");
    adv_set_button_fun(main_data.b[1], "adv_get_object");

    bunny_set_context((t_bunny_context *)&context);
    bunny_loop(main_data.win, WIN_FPS, &main_data);

    adv_main_free(main_data);

    return (0);
}
