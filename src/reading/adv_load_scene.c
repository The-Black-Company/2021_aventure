#include "inc.h"

t_scene *adv_load_scene(const char *file)
{
    t_bunny_configuration *cnf;
    t_scene *scene;
    int i;
    int tmp;
    const char *key;
    const char *src;
    const char *img;
    double time;
    t_content data;

    if ((cnf = bunny_open_configuration(file, NULL)) == NULL)
        return (NULL);
    scene = malloc(sizeof(t_scene));
    bunny_configuration_getf(cnf, &scene->name, "Scene.Name");
    bunny_configuration_getf(cnf, &img, "Scene.Image");
    scene->background = bunny_load_pixelarray(img);
    scene->gr = graph_new(sizeof(t_content));
    for (i = 0; bunny_configuration_getf(cnf, NULL, "Nodes[%d]", i); i = i + 1)
    {
        if (bunny_configuration_getf(cnf, &key, "Nodes[%d].Key", i))
        {
            if (graph_get(scene->gr, key) != NULL)
                return (NULL);
            bunny_configuration_getf(cnf, &data.pos.x, "Nodes[%d].Coord[0]", i);
            bunny_configuration_getf(cnf, &data.pos.y, "Nodes[%d].Coord[1]", i);
            bunny_configuration_getf(cnf, &data.radius.x, "Nodes[%d].Radius[0]", i);
            bunny_configuration_getf(cnf, &data.radius.y, "Nodes[%d].Radius[1]", i);
            bunny_configuration_getf(cnf, &tmp, "Nodes[%d].Scene", i);
            data.scene = tmp;
            bunny_configuration_getf(cnf, &tmp, "Nodes[%d].Default", i);
            data.state = tmp;
            bunny_configuration_getf(cnf, &tmp, "Nodes[%d].Object", i);
            data.obj = tmp;
            bunny_configuration_getf(cnf, &tmp, "Nodes[%d].Condition", i);
            data.condition = tmp;
            graph_push(scene->gr, key, &data);
        }
    }
    for (i = 0; bunny_configuration_getf(cnf, NULL, "Links[%d]", i); i = i + 1)
    {
        if (bunny_configuration_getf(cnf, &key, "Links[%d].Nodes[0]", i) &&
            bunny_configuration_getf(cnf, &src, "Links[%d].Nodes[1]", i) &&
            bunny_configuration_getf(cnf, &time, "Links[%d].Time", i))
        {
            graph_link(scene->gr, key, src, time);
            graph_link(scene->gr, src, key, time);
        }
    }
    return (scene);
}
