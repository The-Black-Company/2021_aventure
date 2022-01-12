#include "inc.h"

void adv_text_color (t_bunny_pixelarray *font, 
					 unsigned int color)
{
  font->clipable.color_mask.full = color;
}