#include "inc.h"

double adv_pow(double a,
			   double b)
{
	if (a < 0)
		a = abs(a);
	return exp(b * log(a));
}