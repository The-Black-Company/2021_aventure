#include "inc.h"

size_t adv_strlen(const char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i = i + 1)
		;
	return (i);
}