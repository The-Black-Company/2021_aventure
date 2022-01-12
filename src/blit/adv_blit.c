#include "inc.h"

static t_bunny_accurate_position e89_two_rotate(t_bunny_accurate_position start, double angle)
{
    t_bunny_accurate_position pos;
    pos.x = (start.x * cos(angle) + start.y * sin(angle));
    pos.y = (-start.x * sin(angle) + start.y * cos(angle));
    return pos;
}

// static double getlen (t_bunny_accurate_position pos)
// {
// 	return sqrt (adv_pow (pos.x, 2) + adv_pow (pos.y, 2));
// }

void adv_blit(t_bunny_pixelarray *target,
              t_bunny_pixelarray *src,
              const t_bunny_position *pos)
{

    //			   	printf("color = %d\n", src->clipable.color_mask.full);

    t_bunny_accurate_position a_src_point[2];
    t_bunny_accurate_position a_targ_point[2];
    t_bunny_accurate_position aa_targ_point[2];

    if (src->clipable.scale.y <= 1)
    {
        for (/**********Variables**********/
             a_src_point[0].x = (double)src->clipable.clip_x_position,
             a_src_point[0].y = (double)src->clipable.clip_y_position,
             a_src_point[1].x = (double)src->clipable.clip_x_position + (double)src->clipable.clip_width,
             a_src_point[1].y = (double)src->clipable.clip_y_position,
             a_targ_point[0].x = 0.0,
             a_targ_point[0].y = 0.0,
             a_targ_point[1].x = 0.0 + ((double)src->clipable.clip_width * src->clipable.scale.x),
             a_targ_point[1].y = 0.0;
             /**********Conditions**********/
             a_src_point[0].y < src->clipable.clip_y_position + src->clipable.clip_height;
             /**********Incrementation**********/
             a_targ_point[0].y += (double)src->clipable.scale.y,
             a_targ_point[1].y += (double)src->clipable.scale.y,
             a_src_point[0].y += 1.0,
             a_src_point[1].y += 1.0)
        {

            aa_targ_point[0] = e89_two_rotate(a_targ_point[0], src->clipable.rotation);
            aa_targ_point[1] = e89_two_rotate(a_targ_point[1], src->clipable.rotation);

            if (pos != NULL)
            {
                aa_targ_point[0].x += (double)pos->x;
                aa_targ_point[0].y += (double)pos->y;
                aa_targ_point[1].x += (double)pos->x;
                aa_targ_point[1].y += (double)pos->y;
            }

            adv_line_cpy(target, src, aa_targ_point, a_src_point);
        }
    }
    else
    {
        for (/**********Variables**********/
             a_src_point[0].x = (double)src->clipable.clip_x_position,
             a_src_point[0].y = (double)src->clipable.clip_y_position,
             a_src_point[1].x = (double)src->clipable.clip_x_position + (double)src->clipable.clip_width,
             a_src_point[1].y = (double)src->clipable.clip_y_position,
             a_targ_point[0].x = 0.0,
             a_targ_point[0].y = 0.0,
             a_targ_point[1].x = 0.0 + ((double)src->clipable.clip_width * src->clipable.scale.x),
             a_targ_point[1].y = 0.0;
             /**********Conditions**********/
             a_src_point[0].y < src->clipable.clip_y_position + src->clipable.clip_height;
             /**********Incrementation**********/
             a_src_point[0].y += (double)1 / src->clipable.scale.y,
             a_src_point[1].y += (double)1 / src->clipable.scale.y,
             a_targ_point[0].y += 1.0,
             a_targ_point[1].y += 1.0)
        {

            aa_targ_point[0] = e89_two_rotate(a_targ_point[0], src->clipable.rotation);
            aa_targ_point[1] = e89_two_rotate(a_targ_point[1], src->clipable.rotation);

            if (pos != NULL)
            {
                aa_targ_point[0].x += (double)pos->x;
                aa_targ_point[0].y += (double)pos->y;
                aa_targ_point[1].x += (double)pos->x;
                aa_targ_point[1].y += (double)pos->y;
            }

            adv_line_cpy(target, src, aa_targ_point, a_src_point);
        }
    }
}

void adv_blit_img(t_bunny_pixelarray *target,
                  t_bunny_pixelarray *src,
                  const t_bunny_position *pos)
{

    t_bunny_accurate_position a_src_point[2];
    t_bunny_accurate_position a_targ_point[2];
    t_bunny_accurate_position aa_targ_point[2];

    if (src->clipable.scale.y <= 1)
    {
        for (/**********Variables**********/
             a_src_point[0].x = (double)src->clipable.clip_x_position,
             a_src_point[0].y = (double)src->clipable.clip_y_position,
             a_src_point[1].x = (double)src->clipable.clip_x_position + (double)src->clipable.clip_width,
             a_src_point[1].y = (double)src->clipable.clip_y_position,
             a_targ_point[0].x = 0.0,
             a_targ_point[0].y = 0.0,
             a_targ_point[1].x = 0.0 + ((double)src->clipable.clip_width * src->clipable.scale.x),
             a_targ_point[1].y = 0.0;
             /**********Conditions**********/
             a_src_point[0].y < (src->clipable.clip_y_position) + src->clipable.clip_height;
             /**********Incrementation**********/
             a_targ_point[0].y += (double)src->clipable.scale.y,
             a_targ_point[1].y += (double)src->clipable.scale.y,
             a_src_point[0].y += 1.0,
             a_src_point[1].y += 1.0)
        {

            aa_targ_point[0] = a_targ_point[0];
            aa_targ_point[1] = a_targ_point[1];

            if (pos != NULL)
            {
                aa_targ_point[0].x += (double)pos->x;
                aa_targ_point[0].y += (double)pos->y;
                aa_targ_point[1].x += (double)pos->x;
                aa_targ_point[1].y += (double)pos->y;
            }

            adv_line_cpy_img(target, src, aa_targ_point, a_src_point);
        }
    }
}