#include "inc.h"

char *adv_strcpy(char *dest,
				 const char *src)
{
	size_t i;

	for (i = 0; src[i] != '\0'; i = i + 1)
		dest[i] = src[i];
	dest[i] = src[i];
	return (dest);
}
