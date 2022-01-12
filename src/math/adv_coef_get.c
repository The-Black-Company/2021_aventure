#include "inc.h"

void adv_coef_get(t_bunny_position pos1,
				  t_bunny_position pos2,
				  float *a,
				  float *b)
{
	*a = 0;
	if (pos1.x != pos2.x)
		*a = (float)(pos1.y - pos2.y) / (pos1.x - pos2.x);
	*b = pos2.y - ((*a) * pos2.x);
}