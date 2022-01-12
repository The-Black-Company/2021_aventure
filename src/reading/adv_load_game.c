#include "inc.h"

t_game *adv_load_game(void)
{
    struct dirent **file;
    int n;
    int i;
    t_game *game;
    char *name;

    game = malloc(sizeof(t_game));
    game->state = GAM_PROGRESS;
    game->current_scene = 0;
    game->nbr_scene = 0;
    n = scandir("./assets/", &file, 0, alphasort);
    for (i = 0; i < n; i = i + 1)
    {
        if (adv_strcmp(file[i]->d_name, ".") != 0 && adv_strcmp(file[i]->d_name, "..") != 0)
        {
            if (game->nbr_scene != 0)
                game->scenes = adv_realloc(game->scenes, (sizeof(t_scene *) * (game->nbr_scene)), (sizeof(t_scene *) * (game->nbr_scene + 1)));
            else
                game->scenes = malloc(sizeof(t_scene *));
            name = adv_strcat("./assets/", file[i]->d_name);
            if((game->scenes[game->nbr_scene] = adv_load_scene(name)) == NULL)
	        return (NULL);
            free(name);
            game->nbr_scene = game->nbr_scene + 1;
        }
        free(file[i]);
    }
    free(file);
    game->player = adv_new_player("res/stickman.png");
    return (game);
}
