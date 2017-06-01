/*
** my_alpha_blit.c for zad in /home/debrau_c/Documents/Igraph/gfx_tekadventure/srcs
** 
** Made by debrau_c
** Login   <debrau_c@epitech.net>
** 
** Started on  Wed Mar  2 17:20:58 2016 debrau_c
** Last update Sun Apr 17 16:53:49 2016 debrau_c
*/

#include <lapin.h>
#include "mylapin.h"

void			my_blit_fond(t_bunny_pixelarray *win,
				     t_bunny_pixelarray *pix,
				     t_bunny_position *pos)
{
  t_bunny_position	pos_in;
  t_bunny_position	pos_out;

  pos_in.x = (pos == NULL) ? 0: pos->x;
  pos_out.x = 0;
  while (pos_in.x < pix->clipable.clip_width)
    {
      pos_in.y = (pos == NULL) ? 0: pos->y;
      pos_out.y = 0;
      while (pos_in.y < pix->clipable.clip_height)
	{
	  tekpixel(win, &pos_out, get_color(pix, &pos_in));
	  pos_in.y++;
	  pos_out.y++;
	}
      pos_in.x++;
      pos_out.x++;
    }
}

int			test_if_colorize(t_bunny_pixelarray *pix,
					 t_bunny_position pos)
{
  if (pos.x < 0 || pos.y < 0
      || pos.x > pix->clipable.clip_width
      || pos.y > pix->clipable.clip_height)
    return (0);
  return (1);
}

void			my_alpha_incr(t_bunny_position *pos1,
				      t_bunny_position *pos2,
				      int index)
{
  if (index)
    {
      pos1->x = pos1->x + 1;
      pos2->x = pos2->x + 1;
    }
  else
    {
      pos1->y = pos1->y + 1;
      pos2->y = pos2->y + 1;
    }
}

void			my_alpha_blit(t_bunny_pixelarray *win,
				      t_bunny_pixelarray *pix,
				      t_bunny_position *pos,
				      t_bunny_rect *rect)
{
  t_bunny_position	pos_tmp;
  t_bunny_position	pos_img;
  unsigned int		col;
  int			i;
  int			j;

  col = 0xFFFF00FF;
  pos_img.x = (rect == NULL) ? 0 : rect->x;
  pos_tmp.x = (pos == NULL) ? 0 : pos->x;
  i = (rect == NULL) ? -1 : rect->x - 1;
  while (++i < ((rect == NULL) ? pix->clipable.clip_width : rect->w + rect->x))
    {
      j = (rect == NULL) ? -1 : rect->y - 1;
      pos_img.y = (rect == NULL) ? 0 : rect->y;
      pos_tmp.y = (pos == NULL) ? 0: pos->y;
      while (++j < ((rect == NULL) ?
		  pix->clipable.clip_height : rect->h + rect->y))
	{
	  if (get_color(pix, &pos_img) != col)
	    tekpixel(win, &pos_tmp, get_color(pix, &pos_img));
	  my_alpha_incr(&pos_img, &pos_tmp, 0);
	}
      my_alpha_incr(&pos_img, &pos_tmp, 1);
    }
}
