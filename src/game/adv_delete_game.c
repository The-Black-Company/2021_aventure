#include "inc.h"

void adv_delete_game(t_game *game)
{
    size_t i;

    for (i = 0; i < game->nbr_scene; i = i + 1)
    {
        bunny_delete_clipable(&game->scenes[i]->background->clipable);
        graph_delete(game->scenes[i]->gr);
        free(game->scenes[i]);
    }
    free(game->scenes);
    bunny_delete_clipable(&game->player.sprites->clipable);
    free(game->player.inventory.objs);
    free(game);
}