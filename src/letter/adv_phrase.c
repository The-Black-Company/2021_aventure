#include "inc.h"

void adv_phrase(t_bunny_pixelarray *px,
                t_bunny_pixelarray *font,
                t_bunny_position pos,
                char *l)
{

    t_bunny_position draw;
    draw = pos;
    for (int i = 0; l[i] != '\0'; ++i)
    {
        adv_letter(px, font, draw, l[i]);
        draw.x += font->clipable.clip_width / 45;
    }
}

static int is_pair(int nb)
{
    return nb % 2;
}

static int width_center(char *wd, int o, int t)
{
    int i;
    int tps;
    i = o;
    tps = i;
    while (wd[i] != '\n' && wd[i] != '\0')
        i++;

    if (is_pair((i - tps)) == 0)
        return t * ((i - tps) / 2);
    else
        return t * ((i - tps) / 2) + (t / 2);
}

static int width_right(char *wd)
{
    int o;
    int i;
    int tps;
    o = 0;
    i = o;
    tps = i;
    while (wd[i] != '\0')
    {
        if (wd[i] == '\n')
        {
            tps = o;
            o = -1;
        }
        o++;
        i++;
    }

    if (o > tps)
        tps = o;
    return (tps);
}

static int width_left(char *wd, int o)
{
    int i;
    int tps;
    i = o;
    tps = i;
    while (wd[i] != '\n' && wd[i] != '\0')
        i++;

    return width_right(wd) - (i - tps);
}

void adv_phrase_a(t_bunny_pixelarray *px,
                  t_bunny_pixelarray *font,
                  t_word_data wd)
{

	t_bunny_position draw;
	draw = wd.pos;

	if (wd.positionnement == center)
		draw.x -= (width_center(wd.mots, 0, (font->clipable.clip_width / 45))) * font->clipable.scale.x;

	if (wd.positionnement == right)
		draw.x = wd.pos.x - (width_right(wd.mots) * (font->clipable.clip_width / 45)) * font->clipable.scale.x;	

	if (wd.positionnement == left)
		draw.x = wd.pos.x + (width_left(wd.mots, 0) * (font->clipable.clip_width / 45)) * font->clipable.scale.x;

	for (int i = 0; wd.mots[i] != '\0'; ++i)
	{
		adv_letter(px, font, draw, wd.mots[i]);
		draw.x += (font->clipable.clip_width / 45) * font->clipable.scale.x + 1;
		if (wd.mots[i] == '\n')
		{
			if (wd.positionnement == center)
				draw.x = wd.pos.x - (width_center(wd.mots, i + 1, (font->clipable.clip_width / 45))) * font->clipable.scale.x;

			if (wd.positionnement == right)
				draw.x = wd.pos.x - (width_right(wd.mots) * (font->clipable.clip_width / 45)) * font->clipable.scale.x;

			if (wd.positionnement == left)
				draw.x = wd.pos.x + (width_left(wd.mots, i + 1) * (font->clipable.clip_width / 45)) * font->clipable.scale.x;

            draw.y += font->clipable.clip_height * font->clipable.scale.y;
        }
    }
}