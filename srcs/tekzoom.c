/*
** my_tekzoom.c for azd in /home/debrau_c/Documents/Igraph/gfx_tekadventure
** 
** Made by debrau_c
** Login   <debrau_c@epitech.net>
** 
** Started on  Wed Mar 30 08:08:19 2016 debrau_c
** Last update Mon Apr 11 15:18:12 2016 debrau_c
*/

#include <lapin.h>
#include "mylapin.h"
#include "my_inc.h"

t_bunny_pixelarray	*tekzoom_creat(t_bunny_pixelarray *past,
				       float zoom)
{
  t_bunny_pixelarray	*new;
  int	max_x;
  int	max_y;

  max_x = past->clipable.clip_width * zoom;
  max_y = past->clipable.clip_height * zoom;
  new = bunny_new_pixelarray(max_x, max_y);
  return (new);
}

t_bunny_pixelarray	*tekzoom(t_bunny_pixelarray *past,
				 float zoom)
{
  t_bunny_pixelarray	*new;
  t_bunny_position	new_pos;
  t_bunny_position	past_pos;

  if ((new = tekzoom_creat(past, zoom)) == NULL)
    return (NULL);
  new_pos.y = 0;
  past_pos.y = new_pos.y / zoom;
  while (new_pos.y < new->clipable.clip_height
	 && past_pos.y < past->clipable.clip_height)
    {
      past_pos.y = new_pos.y / zoom;
      new_pos.x = 0;
      past_pos.x = new_pos.x / zoom;
      while (new_pos.x < new->clipable.clip_width
	     && past_pos.x < past->clipable.clip_width)
	{
	  past_pos.x = new_pos.x / zoom;
	  tekpixel(new, &new_pos, get_color(past, &past_pos));
	  new_pos.x++;
	}
      new_pos.y++;
    }
  return (new);
}
