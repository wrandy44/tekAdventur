/*
** edit_loop_mouse.c for azd in /home/debrau_c/Documents/Igraph/gfx_tekadventure/srcs
** 
** Made by debrau_c
** Login   <debrau_c@epitech.net>
** 
** Started on  Sun Apr 17 00:32:27 2016 debrau_c
** Last update Sun Apr 17 17:43:35 2016 debrau_c
*/

#include <lapin.h>
#include "editeur.h"
#include "mylapin.h"

void			edit_mouse_define_node(t_edit *edit,
					       t_bunny_position *mouse)
{
  t_e_node		*tmp;

  if ((tmp = edit->zone.nodes) == NULL)
    edit->zone.nodes = push_node(mouse);
  else
    {
      while (tmp->next != NULL) tmp = tmp->next;
      tmp->next = push_node(mouse);
    }
}

t_bunny_response	edit_mouse(t_bunny_event_state state,
				   t_bunny_mousebutton button,
				   void *data)
{
  t_bunny_position	*mouse;
  t_edit		*edit;

  edit = data;
  if ((mouse = (t_bunny_position *)bunny_get_mouse_position()) == NULL)
    return (EXIT_ON_ERROR);
  if (state == GO_DOWN && button == BMB_LEFT && !edit->control.on_fleche)
    {
      if (edit->control.mouse_state == DEFINE_NODE)
	edit_mouse_define_node(edit, mouse);
      else if (edit->control.mouse_state == DEFINE_END
	       || edit->control.mouse_state == DEFINE_START)
	edit_define_important_node(mouse, &edit->zone, edit->control.mouse_state);
    }
  if (state == GO_UP && button == BMB_LEFT && edit->control.on_fleche)
    if (edit_gest_menu(edit, mouse) == 2)
      return (EXIT_ON_SUCCESS);
  if (edit->control.mouse_state == RELIE_NODE
      && state == GO_DOWN && button == BMB_LEFT
      && !edit->control.on_fleche)
    edit_relie_node(mouse, &edit->zone, &edit->control);
  return (GO_ON);
}
