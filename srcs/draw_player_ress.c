/*
** draw_player_ress.c for azd in /home/debrau_c/Documents/Igraph/gfx_tekadventure/srcs
** 
** Made by debrau_c
** Login   <debrau_c@epitech.net>
** 
** Started on  Mon Apr 11 12:33:30 2016 debrau_c
** Last update Mon Apr 11 15:23:19 2016 debrau_c
*/

#include "my_inc.h"

t_bunny_pixelarray	*draw_copy_player(t_bunny_pixelarray *img_p,
					  t_bunny_rect rect_p)
{
  t_bunny_pixelarray	*new;
  t_bunny_position	pos;
  t_bunny_position	pos2;
  unsigned int		col;

  if ((new = bunny_new_pixelarray(rect_p.w, rect_p.h)) == NULL)
    return (NULL);
  pos.x = 0;
  pos2.x = rect_p.x;
  while (pos.x < rect_p.w)
    {
      pos.y = 0;
      pos2.y = rect_p.y;
      while (pos.y < rect_p.h)
	{
	  col = get_color(img_p, &pos2);
	  tekpixel(new, &pos, col);
	  pos2.y++;
	  pos.y++;
	}
      pos2.x++;
      pos.x++;
    }
  return (new);
}
