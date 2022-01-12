#include "inc.h"

unsigned char mix_pal(unsigned char a,
					  unsigned char b,
					  double t)
{
	unsigned char res;
	double x;
	double y;
	x = (double)a * (1 - t);
	y = (double)b * t;
	res = (unsigned char)x + (unsigned char)y;
	return res;
}