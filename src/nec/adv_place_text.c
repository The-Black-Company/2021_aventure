#include "inc.h"

void adv_place_text (char *dest, char *src)
{
	int i;
	for (i = 0; src[i] != '\0'; ++i)
			dest[i] = src[i];
	dest[i] = src[i];
}