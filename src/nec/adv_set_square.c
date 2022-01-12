#include "inc.h"


static void adv_set_line_square (t_bunny_pixelarray *px,
					t_bunny_position *pos,
					unsigned int color)
{
	t_bunny_position a;
	t_bunny_position b;

	if(pos[0].x < pos[1].x)
	{
		a.x = pos[0].x;
		b.x = pos[1].x;
	}
	else
	{
		a.x = pos[1].x;
		b.x = pos[0].x;
	}

	
	for (a.y = pos[0].y, b.y = pos[1].y; a.x < b.x; ++a.x, --b.x)
	{
		adv_set_pixel(px, a, color);
		adv_set_pixel(px, b, color);
	}
}


void adv_set_square(t_bunny_pixelarray *px,
					t_bunny_position *pos,
					unsigned int color)
{
	t_bunny_position line[2];
	line[0] = pos[0];
	line[1] = pos[1];

	for (line[1].y = pos[0].y; line[1].y < pos[1].y; ++line[0].y, ++line[1].y)
	{
		adv_set_line_square(px, line, color);
	}
}