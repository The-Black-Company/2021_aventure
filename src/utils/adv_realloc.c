#include "inc.h"

void *adv_realloc(void *ptr,
				  size_t old_size,
				  size_t new_size)
{
	char *output;
	char *input;
	size_t i;
	size_t tern;

	if ((output = malloc(new_size)) == NULL)
		return (NULL);
	input = ptr;
	tern = (old_size <= new_size ? old_size : new_size);
	for (i = 0; i < tern; i = i + 1)
		output[i] = input[i];
	free(ptr);
	return (output);
}
