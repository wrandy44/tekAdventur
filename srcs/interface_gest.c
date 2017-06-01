/*
** interface_gest.c for azd in /home/debrau_c/Documents/Igraph/gfx_tekadventure
** 
** Made by debrau_c
** Login   <debrau_c@epitech.net>
** 
** Started on  Wed Mar 30 04:12:21 2016 debrau_c
** Last update Wed Mar 30 04:34:43 2016 debrau_c
*/

#include "my_inc.h"

int	interface_check_fleche(t_interface *inter,
			       t_bunny_position *mouse)
{
  int	max_x;
  int	max_y;

  if (inter->menu_on)
    {
      if (mouse->y < SCREEN_H - 200)
	{
	  inter->menu_on = 0;
	  inter->sac_on = 0;
	}
      return (0);
    }
  max_x = inter->fleche_pos.x + inter->img_fleche->clipable.clip_width;
  max_y = inter->fleche_pos.y + inter->img_fleche->clipable.clip_height;
  if (mouse->x > inter->fleche_pos.x
      && mouse->x < max_x
      && mouse->y > inter->fleche_pos.y
      && mouse->y < max_y)
    inter->menu_on = 1;
  return (0);
}
