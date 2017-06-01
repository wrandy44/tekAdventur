/*
** edit_node_gest.c for zad in /home/debrau_c/Documents/Igraph/gfx_tekadventure
** 
** Made by debrau_c
** Login   <debrau_c@epitech.net>
** 
** Started on  Fri Apr 15 16:36:10 2016 debrau_c
** Last update Sun Apr 17 18:30:26 2016 debrau_c
*/

#include <lapin.h>
#include "editeur.h"
#include "my_string.h"
#include "my_realloc.h"

t_e_node	*push_node(t_bunny_position *mouse)
{
  t_e_node	*new;
  static int	i = 0;

  if ((new = bunny_malloc(sizeof(t_e_node))) == NULL)
    return (NULL);
  new->pos.x = mouse->x;
  new->pos.y = mouse->y;
  new->start = -1;
  new->end = -1;
  new->index = i++;
  new->next = NULL;
  return (new);
}

int	edit_up_chemin(t_control *control, t_edit_zone *zone)
{
  int	size;

  if (zone->chemin == NULL)
    {
      if ((zone->chemin = bunny_malloc(sizeof(char) * 3)) == NULL)
	return (1);
      zone->chemin[0] = control->index_first_node + 1;
      zone->chemin[1] = control->index_second_node + 1;
      zone->chemin[2] = '\0';
    }
  else
    {
      if ((zone->chemin = my_realloc(zone->chemin,
				     my_strlen(zone->chemin))) == NULL)
	return (1);
      size = my_strlen(zone->chemin);
      zone->chemin[size] = control->index_first_node + 1;
      zone->chemin[size + 1] = control->index_second_node + 1;
      zone->chemin[size + 2] = '\0';
    }
  return (0);
}

int			edit_relie_node(t_bunny_position *mouse,
					t_edit_zone *zone,
					t_control *control)
{
  t_e_node		*tmp;
  t_bunny_position	start;

  tmp = zone->nodes;
  while (tmp != NULL)
    {
      start.x = tmp->pos.x - 20;
      start.y = tmp->pos.y - 20;
      if (mouse->x > start.x && mouse->x < start.x + 40
	  && mouse->y > start.y && mouse->y < start.y + 40)
	{
	  if (control->index_first_node == -1)
	    control->index_first_node = tmp->index;
	  else control->index_second_node = tmp->index;
	}
      tmp = tmp->next;
    }
  if (control->index_second_node == -1) return (0);
  edit_up_chemin(control, zone);
  control->index_second_node = -1;
  control->index_first_node = -1;
  return (0);
}

int	edit_define_important_node(t_bunny_position *mouse,
				   t_edit_zone *zone,
				   int mouse_state)
{
  t_e_node	*tmp;
  int		start_x;
  int		start_y;

  tmp = zone->nodes;
  while (tmp != NULL)
    {
      start_x = tmp->pos.x - 20;
      start_y = tmp->pos.y - 20;
      if (mouse->x > start_x && mouse->x < start_x + 40
	  && mouse->y > start_y && mouse->y < start_y + 40)
	{
	  if (mouse_state == DEFINE_END) tmp->end = 1;
	  else tmp->start = 1;
	}
      tmp = tmp->next;
    }
  return (0);
}
