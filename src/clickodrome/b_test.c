#include "inc.h"

static bool b_test_square(t_button *b,
						  t_bunny_position pos)
{
	if (b->type == square)
		if (b->data.pos.x <= pos.x && b->data.pos.x + b->data.width >= pos.x)
			if (b->data.pos.y <= pos.y && b->data.pos.y + b->data.height >= pos.y)
				return true;
	return false;
}

static bool b_test_circle(t_button *b,
						  t_bunny_position pos)

{

	if (adv_pow(b->data.radius, 2) >= adv_pow(pos.x - b->data.pos.x, 2) + adv_pow(pos.y - b->data.pos.y, 2))
		return true;
	else
		return false;
}

static bool b_test_oval(t_button *b,
						t_bunny_position pos)

{

	if ((((adv_pow (pos.x - b->data.pos.x, 2) / (double) adv_pow(b->data.orad.x, 2))) +
		 ((adv_pow (pos.y - b->data.pos.y, 2) / (double) adv_pow(b->data.orad.y, 2)))) <= 1)
		return true;
	else
		return false;
}

bool b_test(t_button *b,
			t_bunny_position pos)
{

	bool res;
	res = false;

	if (bunny_get_mouse_button()[BMB_LEFT] && b->isClick == true)
	{

		if (b->type == square)
			res = b_test_square(b, pos);
		if (b->type == rectangle)
			res = b_test_square(b, pos);
		if (b->type == circle)
			res = b_test_circle(b, pos);
		if (b->type == ovale)
			res = b_test_oval(b, pos);
	}
	return (res);
}
