#include "inc.h"

unsigned int adv_circle_gradient(double dist,
								 int radius,
								 unsigned int color1,
								 unsigned int color2)
{
	t_bunny_color clr[2];

	clr[0].full = color1;
	clr[1].full = color2;
	clr[0].argb[RED_CMP] = (clr[1].argb[RED_CMP] * (dist / radius)) + (clr[0].argb[RED_CMP] * (1 - (dist / radius)));
	clr[0].argb[GREEN_CMP] = (clr[1].argb[GREEN_CMP] * (dist / radius)) + (clr[0].argb[GREEN_CMP] * (1 - (dist / radius)));
	clr[0].argb[BLUE_CMP] = (clr[1].argb[BLUE_CMP] * (dist / radius)) + (clr[0].argb[BLUE_CMP] * (1 - (dist / radius)));
	clr[0].argb[ALPHA_CMP] = (clr[1].argb[ALPHA_CMP] * (dist / radius)) + (clr[0].argb[ALPHA_CMP] * (1 - (dist / radius)));
	return (clr[0].full);
}