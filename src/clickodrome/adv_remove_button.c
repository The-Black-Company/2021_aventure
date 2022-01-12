#include "inc.h"

void adv_remove_button (t_button *b)
{
	dlclose(b->dlh);
	free(b);
}