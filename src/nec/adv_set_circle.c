#include "inc.h"

void adv_set_circle(t_bunny_pixelarray *px,
					t_bunny_position pos,
					int radius,
					unsigned int *color)
{
	int *pix;
	int i;
	int j;
	int width;
	double dist;

	width = px->clipable.buffer.width;
	pix = (int *)px->pixels;
	i = ((width * pos.y) + pos.x) - (radius * width) - radius;
	j = i;
	while (i != ((width * pos.y) + pos.x) + (radius * width) + radius)
	{
		dist = sqrt(adv_pow((pos.x - ((i % width) - 1)), 2) + adv_pow((pos.y - ((i / width))), 2));
		if (dist <= radius)
			pix[i] = mix_color(pix[i], adv_circle_gradient(dist, radius, color[0], color[1]));
		if (i == j + (2 * radius))
		{
			i = i - (2 * radius) + width;
			j = i;
		}
		else
			i = i + 1;
	}
}
