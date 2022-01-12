#include "inc.h"

void adv_dot(t_main_data *data,
             double index)
{
    t_node *start;
    t_node *end;
    t_content *nc;
    t_content *nc2;
    int dist;
    int tdist;
    int cdist;
    t_bunny_position center;
    t_bunny_position pos[2];
    size_t i;
    t_node *temp;
    double safeindex;

    graph_get_selectors(data->game->scenes[data->game->current_scene]->gr, &start, &end);
    nc2 = start->data;
    graph_path_reset(data->game->scenes[data->game->current_scene]->gr);
    graph_shortest_path(data->game->scenes[data->game->current_scene]->gr, start->key, end->key);
    dist = 0;
    while (start != end)
    {
        temp = adv_set_value(start);
        i = 0;
        while (start->nodes[i] != NULL && temp == start)
        {
            if (start->nodes[i]->step == -2)
            {
                nc = start->nodes[i]->data;
                pos[0].x = nc2->pos.x;
                pos[0].y = nc2->pos.y;
                pos[1].x = nc->pos.x;
                pos[1].y = nc->pos.y;
                dist = sqrt(adv_pow(pos[1].x - pos[0].x, 2) + adv_pow(pos[1].y - pos[0].y, 2)) + dist;
                start = start->nodes[i];
                nc2 = nc;
            }
            i = i + 1;
        }
    }
    graph_path_reset(data->game->scenes[data->game->current_scene]->gr);
    graph_get_selectors(data->game->scenes[data->game->current_scene]->gr, &start, &end);
    nc2 = start->data;
    graph_shortest_path(data->game->scenes[data->game->current_scene]->gr, start->key, end->key);
    tdist = 0;
    while (start != end)
    {
        temp = adv_set_value(start);
        i = 0;
        while (start->nodes[i] != NULL && temp == start)
        {
            if (start->nodes[i]->step == -2)
            {
                nc = start->nodes[i]->data;
                pos[0].x = nc2->pos.x;
                pos[0].y = nc2->pos.y;
                pos[1].x = nc->pos.x;
                pos[1].y = nc->pos.y;
                cdist = sqrt(adv_pow(pos[1].x - pos[0].x, 2) + adv_pow(pos[1].y - pos[0].y, 2));
                tdist = cdist + tdist;
                if (tdist >= (dist * index))
                {
                    safeindex = ((dist * index) / tdist);
                    safeindex = 1 - safeindex;
                    safeindex = ((tdist * safeindex) / cdist);
                    safeindex = 1 - safeindex;
                    center.x = (safeindex * pos[1].x) + ((1 - safeindex) * pos[0].x);
                    center.y = (safeindex * pos[1].y) + ((1 - safeindex) * pos[0].y);
                    adv_move_player(data->px, data->game->player.sprites, center, pos[0].x < pos[1].x ? 1 : 0);
                    return;
                }
                start = start->nodes[i];
                nc2 = nc;
            }
            i = i + 1;
        }
    }
}
