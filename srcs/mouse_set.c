/*
** mouse_set.c for azd in /home/debrau_c/Documents/Igraph/gfx_tekadventure
** 
** Made by debrau_c
** Login   <debrau_c@epitech.net>
** 
** Started on  Wed Mar 30 06:21:32 2016 debrau_c
** Last update Sun Apr 17 16:55:06 2016 debrau_c
*/

#include "my_inc.h"

int			mouse_click_define_action(t_interface *inter,
						  t_bunny_position *mouse_pos)
{
  if (mouse_pos->x > inter->bar_pos.x + 50
      && mouse_pos->x < inter->bar_pos.x + 280
      && mouse_pos->y > inter->bar_pos.y + 40
      && mouse_pos->y < inter->bar_pos.y + 100)
    return (RAMASSER);
  if (mouse_pos->x > inter->bar_pos.x + 280
      && mouse_pos->x < inter->bar_pos.x + 560
      && mouse_pos->y > inter->bar_pos.y + 40
      && mouse_pos->y < inter->bar_pos.y + 100)
    return (OUVRIR);
  return (RIEN);
}

int			mouse_click_interface(t_main_struct *tmp,
					      t_bunny_position *mouse)
{
  int			action;

  if (mouse->x >SCREEN_W - 150 && mouse->x < SCREEN_W - 40
      && mouse->y > SCREEN_H - 200 && mouse->y < SCREEN_H - 40)
    tmp->interface->sac_on = (tmp->interface->sac_on)? 0 : 1;
  if (!tmp->interface->sac_on)
    {
      action = mouse_click_define_action(tmp->interface, mouse);
      if (action == RAMASSER)
	action_ramasser(&tmp->player, &tmp->zone[tmp->current_zone -1], tmp);
      if (action == OUVRIR)
	action_ouvrir(&tmp->player, &tmp->zone[tmp->current_zone -1], tmp);
    }
  return (0);
}

t_bunny_response	my_mouse_set(t_bunny_event_state state,
				     t_bunny_mousebutton button,
				     void *data)
{
  t_main_struct		*tmp;
  t_bunny_position	*mouse_pos;
  int			nb_node;

  if ((mouse_pos = (t_bunny_position *)bunny_get_mouse_position()) == NULL)
    return (EXIT_ON_ERROR);
  tmp = (t_main_struct *)data;
  if (button == BMB_LEFT && state == GO_UP)
    {
      if (tmp->interface->menu_on)
	mouse_click_interface(tmp, mouse_pos);
      else if ((nb_node = node_check_click_to_node(mouse_pos,
						   &tmp->zone[tmp->current_zone - 1])) > -1)
	tmp->player.target_node = nb_node;
    }
  return (GO_ON);
}
