#include "inc.h"

static void adv_draw_button_square(t_bunny_pixelarray *px,
								   t_button *b)
{
	t_bunny_position pos[2];
	pos[0] = b->data.pos;
	pos[1] = b->data.pos;
	pos[1].x += b->data.width;
	pos[1].y += b->data.height;
	adv_set_square(px, pos, b->color.full);
}

static void adv_draw_button_circle(t_bunny_pixelarray *px,
								   t_button *b)
{
	unsigned int col[2];
	col[0] = b->color.full;
	col[1] = b->color.full;
	adv_set_circle(px, b->data.pos, b->data.radius, col);
}

static void adv_draw_button_ovale(t_bunny_pixelarray *px,
								  t_button *b)
{
	adv_set_ellipse(px, b->data.pos, b->data.orad, b->color.full);
}

void adv_draw_button(t_bunny_pixelarray *px,
					 t_button *b)
{
	if (b->type == square)
		adv_draw_button_square(px, b);

	if (b->type == rectangle)
		adv_draw_button_square(px, b);

	if (b->type == circle)
		adv_draw_button_circle(px, b);

	if (b->type == ovale)
		adv_draw_button_ovale(px, b);
}