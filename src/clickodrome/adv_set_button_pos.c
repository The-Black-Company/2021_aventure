#include "inc.h"

void adv_set_button_pos(t_button *b,
						int x,
						int y)
{
	b->data.pos.x = x;
	b->data.pos.y = y;
}