#include "inc.h"

void adv_set_button_fun(t_button *b,
						const char *sym)
{
	if ((b->fun = dlsym(b->dlh, sym)) == NULL)
		printf("ERREUR load function\n");
}