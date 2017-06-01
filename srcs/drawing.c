/*
** drawing.c for zad in /home/debrau_c/Documents/Igraph/gfx_tekadventure/srcs
** 
** Made by debrau_c
** Login   <debrau_c@epitech.net>
** 
** Started on  Wed Apr 13 21:18:29 2016 debrau_c
** Last update Sun Apr 17 17:54:35 2016 debrau_c
*/

#include "my_inc.h"

void			draw_interface_sac(t_interface *interface,
					   t_main_struct *mainS)
{
  int			i;
  t_player		*player;
  t_bunny_position	pos;
  int			index;

  player = &mainS->player;
  my_alpha_blit(mainS->fond,
		interface->img_sac,
		&interface->sac_pos,
		NULL);
  i = 0;
  pos.x = interface->sac_pos.x + 10;
  pos.y = interface->sac_pos.y + 10;
  while (i < 5)
    {
      if (!player->sac[i].vide)
	{
	  index = player->sac[i].index_img;
	  my_alpha_blit(mainS->fond,
			mainS->bank->obj[index],
			&pos, NULL);
	}
      pos.x += 30;
      i++;
    }
}

void			draw_interface(t_interface *interface, t_main_struct *mainS)
{
  if (interface->menu_on)
    {
      my_alpha_blit(mainS->fond, interface->img_action_bar,
		    &interface->bar_pos, NULL);
      if (interface->sac_on)
	draw_interface_sac(interface, mainS);
    }
  else
    my_alpha_blit(mainS->fond, interface->img_fleche,
		  &interface->fleche_pos, NULL);
}

void			draw_object_zone(t_zone *one_zone,
					 t_bunny_pixelarray **imgs_obj,
					 t_bunny_pixelarray *fond)
{
  int			i;
  t_object		*obji;

  i = 0;
  obji = one_zone->obj;
  while (i < one_zone->nb_obj)
    {
      if (obji[i].exist && obji[i].pix_index != -1)
	my_alpha_blit(fond, imgs_obj[obji[i].pix_index], &obji[i].pos, NULL);
      i++;
    }
}

