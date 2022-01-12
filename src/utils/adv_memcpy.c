#include "inc.h"

void adv_memcpy(void *output,
				void *input,
				size_t size)
{
	size_t i;
	char *s1;
	char *s2;

	s1 = (char *)output;
	s2 = (char *)input;
	for (i = 0; i < size; i = i + 1)
		s1[i] = s2[i];
}