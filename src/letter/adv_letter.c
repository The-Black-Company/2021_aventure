#include "inc.h"

static int for_zelda_font(char l)
{ // 44 caractères
	int i;

	char *str = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ,!'&.\"?- ";
	char *stra = "0123456789abcdefghijklmnopqrstuvwxyz,!'&.\"?- ";

	for (i = 0; i < 46 && str[i] != l && stra[i] != l; ++i)
	{
	}

	if (i == 46)
		return -1;
	else
		return i;
}

void adv_letter(t_bunny_pixelarray *px,
				t_bunny_pixelarray *font,
				t_bunny_position pos,
				char l)
{

	int i;
	int temp;

	if ((i = for_zelda_font(l)) != -1)
	{
		temp = font->clipable.clip_width;
		font->clipable.clip_width = font->clipable.clip_width / 45;
		font->clipable.clip_x_position = font->clipable.clip_width * i;
		adv_blit(px, font, &pos);
		font->clipable.clip_x_position = 0;
		font->clipable.clip_width = temp;
	}
}