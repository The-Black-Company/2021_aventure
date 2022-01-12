#include "inc.h"

void adv_fill(t_bunny_pixelarray *px,
			  unsigned int color)
{

	unsigned int *caze;
	caze = px->pixels;

	for (int i = 0; i < px->clipable.buffer.width * px->clipable.buffer.height; ++i)
		caze[i] = color;
}

void adv_fill_transp(t_bunny_pixelarray *px,
			  unsigned int color)
{

	unsigned int *caze;
	caze = px->pixels;

	for (int i = 0; i < px->clipable.buffer.width * px->clipable.buffer.height; ++i)
	  caze[i] = mix_color(caze[i], color);
}
