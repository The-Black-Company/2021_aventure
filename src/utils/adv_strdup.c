#include "inc.h"

char *adv_strdup(const char *src)
{
	char *dest;

	dest = malloc(sizeof(char) * (adv_strlen(src) + 1));
	adv_strcpy(dest, src);
	return (dest);
}
