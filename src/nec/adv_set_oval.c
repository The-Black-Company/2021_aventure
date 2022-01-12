#include "inc.h"

void adv_set_ellipse(t_bunny_pixelarray *px,
				  t_bunny_position pos,
				  t_bunny_position radius,
				  unsigned int color)
{
	t_bunny_position pixpos;

	for (pixpos.y = pos.y - radius.y;
		 pixpos.y <= pos.y + radius.y;
		 pixpos.y = pixpos.y + 1)
	{
		for (pixpos.x = pos.x - radius.x;
			 pixpos.x <= pos.x + radius.x;
			 pixpos.x = pixpos.x + 1)
		{
			if ((((adv_pow(pixpos.x - pos.x, 2) / (double)adv_pow(radius.x, 2))) + ((adv_pow(pixpos.y - pos.y, 2) / (double)adv_pow(radius.y, 2)))) <= 1)
				adv_set_pixel(px, pixpos, color);
		}
	}
}
