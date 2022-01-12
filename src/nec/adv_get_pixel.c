#include "inc.h"

unsigned int adv_get_pixel(t_bunny_pixelarray *px,
						   t_bunny_position pos)
{
	unsigned int *caze;

	if (pos.x > 0 || pos.x < px->clipable.buffer.width ||
		pos.y > 0 || pos.y < px->clipable.buffer.height)
	{
		caze = px->pixels;
		return (caze[pos.x + pos.y * px->clipable.buffer.width]);
	}
	return (0);
}