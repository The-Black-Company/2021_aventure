#include "inc.h"

void adv_set_line(t_bunny_pixelarray *px,
				  t_bunny_position *pos,
				  unsigned int color)
{
	t_bunny_position new_pos;
	float a;
	float b;
	int temp;

	adv_coef_get(pos[0], pos[1], &a, &b);
	if (a > -1 && a < 1 && pos[1].x != pos[0].x)
	{
		new_pos = pos[0].x < pos[1].x ? pos[0] : pos[1];
		temp = (pos[0].x < pos[1].x ? pos[1].x : pos[0].x);
		while (new_pos.x <= temp)
		{
			adv_set_pixel(px, new_pos, adv_gradient(pos[0], pos[1], new_pos, color, color));
			new_pos.x = new_pos.x + 1;
			new_pos.y = (a * new_pos.x) + b;
		}
	}
	else
	{
		new_pos = pos[0].y < pos[1].y ? pos[0] : pos[1];
		temp = (pos[0].y < pos[1].y ? pos[1].y : pos[0].y);
		while (new_pos.y <= temp)
		{
			adv_set_pixel(px, new_pos, adv_gradient(pos[0], pos[1], new_pos, color, color));
			new_pos.y = new_pos.y + 1;
			if (a != 0)
				new_pos.x = (new_pos.y - b) / a;
		}
	}
}
