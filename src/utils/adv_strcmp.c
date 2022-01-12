#include "inc.h"

int adv_strcmp(const char *s1,
			   const char *s2)
{
	int i;

	for (i = 0; s1[i] == s2[i] && s1[i] != '\0'; i = i + 1)
		;
	return (s1[i] - s2[i]);
}