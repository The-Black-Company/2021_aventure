#include "inc.h"

void adv_set_pixel(t_bunny_pixelarray *px,
				   t_bunny_position pos,
				   unsigned int color)
{
	if ((pos.x > 0 && pos.x < px->clipable.buffer.width) ||
		(pos.y > 0 && pos.y < px->clipable.buffer.height))
	{
		int i;
		int *caze;
		i = pos.x + pos.y * px->clipable.buffer.width;
		caze = px->pixels;
		caze[i] = mix_color(caze[i], color);
	}
}