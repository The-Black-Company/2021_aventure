#include "inc.h"

void adv_set_button_size_square(t_button *b,
								int s)
{
	b->data.width = s;
	b->data.height = s;
}

void adv_set_button_size_ovale(t_button *b,
							   int s,
							   int sa)
{
	b->data.orad.x = s;
	b->data.orad.y = sa;
}

void adv_set_button_size_circle(t_button *b,
								int s)
{
	b->data.radius = s;
}

void adv_set_button_size_rectangle(t_button *b,
								   t_bunny_size s)
{
	b->data.width = s.x;
	b->data.height = s.y;
}
