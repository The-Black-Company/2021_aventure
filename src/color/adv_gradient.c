#include "inc.h"

unsigned int adv_gradient(t_bunny_position pos1,
						  t_bunny_position pos2,
						  t_bunny_position cpos,
						  unsigned int c1,
						  unsigned int c2)
{
	t_bunny_color clr[2];
	double dist[3];

	dist[0] = sqrt(adv_pow(pos1.x - cpos.x, 2) + adv_pow(pos1.y - cpos.y, 2));
	dist[1] = sqrt(adv_pow(pos2.x - cpos.x, 2) + adv_pow(pos2.y - cpos.y, 2));
	dist[2] = sqrt(adv_pow(pos1.x - pos2.x, 2) + adv_pow(pos1.y - pos2.y, 2));
	clr[0].full = c1;
	clr[1].full = c2;
	clr[0].argb[RED_CMP] = (clr[1].argb[RED_CMP] * (dist[0] / dist[2])) + (clr[0].argb[RED_CMP] * (dist[1] / dist[2]));
	clr[0].argb[GREEN_CMP] = (clr[1].argb[GREEN_CMP] * (dist[0] / dist[2])) + (clr[0].argb[GREEN_CMP] * (dist[1] / dist[2]));
	clr[0].argb[BLUE_CMP] = (clr[1].argb[BLUE_CMP] * (dist[0] / dist[2])) + (clr[0].argb[BLUE_CMP] * (dist[1] / dist[2]));
	clr[0].argb[ALPHA_CMP] = (clr[1].argb[ALPHA_CMP] * (dist[0] / dist[2])) + (clr[0].argb[ALPHA_CMP] * (dist[1] / dist[2]));
	return (clr[0].full);
}
