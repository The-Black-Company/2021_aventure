#include "inc.h"

void adv_move_player (t_bunny_pixelarray *fpx, t_bunny_pixelarray *px, t_bunny_position pos, int move)
{

	if (move != 2)
	{
	    if(px->clipable.clip_x_position + px->clipable.clip_width > px->clipable.buffer.width)
            px->clipable.clip_x_position = 0;
        else
            px->clipable.clip_x_position += px->clipable.clip_width;
    }
    else
    {
    	px->clipable.clip_x_position = 0;
    }

        pos.x -= px->clipable.clip_width / 2;
        pos.y -= px->clipable.clip_height;





		px->clipable.clip_y_position = move * px->clipable.clip_height;
        adv_blit(fpx, px, &pos);


}