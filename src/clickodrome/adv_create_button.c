#include "inc.h"

t_button *adv_create_button(t_bunny_position pos,
							t_type type)
{
	t_button *b;
	b = malloc(sizeof(*b));
	b->data.pos.x = pos.x;
	b->data.pos.y = pos.y;
	b->type = type;
	b->isClick = true;
	b->dlh = dlopen(NULL, RTLD_LAZY);
	b->fun = NULL;
	b->visi = true;
	b->color.full = -1;
	return b;
}

