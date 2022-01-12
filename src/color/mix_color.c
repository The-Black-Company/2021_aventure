#include "inc.h"

unsigned int mix_color(unsigned int a, //couleur de base
					   unsigned int b) // couleur à placer
{
	t_bunny_color clr1;
	t_bunny_color clr2;

	clr1.full = b;
	clr2.full = a;

	clr1.argb[RED_CMP] = (clr2.argb[RED_CMP] * (1.0 - (float)clr1.argb[ALPHA_CMP] / 255)) + clr1.argb[RED_CMP] * ((float)clr1.argb[ALPHA_CMP] / 255);
	clr1.argb[GREEN_CMP] = (clr2.argb[GREEN_CMP] * (1.0 - (float)clr1.argb[ALPHA_CMP] / 255)) + clr1.argb[GREEN_CMP] * ((float)clr1.argb[ALPHA_CMP] / 255);
	clr1.argb[BLUE_CMP] = (clr2.argb[BLUE_CMP] * (1.0 - (float)clr1.argb[ALPHA_CMP] / 255)) + clr1.argb[BLUE_CMP] * ((float)clr1.argb[ALPHA_CMP] / 255);
	return (clr1.full);
}
