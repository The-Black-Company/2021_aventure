#include "inc.h"

static double pythagore (t_bunny_accurate_position *pos)
{
	return ceil(sqrt (adv_pow (pos[1].x - pos[0].x, 2) + adv_pow (pos[1].y - pos[0].y, 2)));
}




void adv_line_cpy(t_bunny_pixelarray *px,
				  t_bunny_pixelarray *cpy,
				  t_bunny_accurate_position *pos,
				  t_bunny_accurate_position *tpos)
{

	t_bunny_position linedrawer;
	t_bunny_position tlinedrawer;
	t_bunny_position mem;
	double points; 
	double adv;



	points = pythagore(pos);
	adv = 1 / points;


	mem.x = -1;
	mem.y = -1;


		for (double i = 0; i < points; i += adv)
		{
			linedrawer.x = pos[0].x + (pos[1].x - pos[0].x) * (i / points);
			linedrawer.y = pos[0].y + (pos[1].y - pos[0].y) * (i / points);
			tlinedrawer.x = tpos[0].x + (tpos[1].x - tpos[0].x) * (i / points);
			tlinedrawer.y = tpos[0].y + (tpos[1].y - tpos[0].y) * (i / points);

			if (mem.x != linedrawer.x || linedrawer.y != mem.y)
			{
				if (linedrawer.x >= 0 && linedrawer.x <= px->clipable.buffer.width && linedrawer.y >= 0 && linedrawer.y <= px->clipable.buffer.height)
				{
					t_bunny_color clr;
					clr.full = adv_get_pixel(cpy, tlinedrawer);
					if ((int) (cpy->clipable.color_mask.full) == -1)
						adv_set_pixel(px, linedrawer, clr.full);
					else if (clr.argb[ALPHA_CMP] != 0)
						adv_set_pixel(px, linedrawer, mix_color(clr.full, cpy->clipable.color_mask.full));
					mem.x = linedrawer.x;
					mem.y = linedrawer.y;
				}
			}

		}
}


void adv_line_cpy_img (t_bunny_pixelarray *px,
				  t_bunny_pixelarray *cpy,
				  t_bunny_accurate_position *pos,
				  t_bunny_accurate_position *tpos)
{
	/*********************************************************************************************************/
	/*                                        Mise en place des variables                                    */
	/*********************************************************************************************************/
	t_bunny_position Linedrawer;  // points mouvant sur le vecteur défini par pos
	t_bunny_position tLinedrawer; // points mouvant sur le vecteur défini par tpos
	double Percentadv;			  // Pourcentage d'écriture des vecteur
	double adv;					  // Avancement du poucentage (peut être remplacer par 0.001 mais varie en fonction du nombre de points)

	/*********************************************************************************************************/
	/*                                       Initialisation des variables                                    */
	/*********************************************************************************************************/
	Percentadv = 0;
	t_bunny_accurate_position max;

	t_bunny_position de;
	de.x = max((tpos[1].x - tpos[0].x), (tpos[0].x - tpos[1].x));
	de.y = max((pos[1].x - pos[0].x), (pos[0].x - pos[1].x));
	max.x = max(de.x, de.y);

	de.x = max((pos[1].y - pos[0].y), (pos[0].y - pos[1].y));
	de.y = max((tpos[1].y - tpos[0].y), (tpos[0].y - tpos[1].y));
	max.y = max(de.x, de.y);
	adv = (double) (1 / ((double) max(max.x, max.y) + 0.5));

	/*********************************************************************************************************/
	/*                                        Boucle traçant le vecteur                                      */
	/*********************************************************************************************************/
	while (Percentadv < 1.0)
	{
		Linedrawer.x = (double) pos[0].x + ((double) Percentadv * (double)(pos[1].x - (double)pos[0].x));
		Linedrawer.y = (double) pos[0].y + ((double) Percentadv * (double)(pos[1].y - (double)pos[0].y));
		tLinedrawer.x = (double) tpos[0].x + ((double) Percentadv * (double)(tpos[1].x - (double)tpos[0].x));
		tLinedrawer.y = (double) tpos[0].y + ((double) Percentadv * (double)(tpos[1].y - (double)tpos[0].y));

		if (Linedrawer.x >= 0 && Linedrawer.x <= px->clipable.buffer.width && Linedrawer.y >= 0 && Linedrawer.y <= px->clipable.buffer.height)
		{
			t_bunny_color clr;
			clr.full = adv_get_pixel(cpy, tLinedrawer);
				adv_set_pixel(px, Linedrawer, clr.full);

		}
		Percentadv += adv;
	}
}