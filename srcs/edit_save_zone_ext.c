/*
** edit_save_end_start.c for azd in /home/debrau_c/Documents/Igraph/gfx_tekadventure
** 
** Made by debrau_c
** Login   <debrau_c@epitech.net>
** 
** Started on  Sun Apr 17 17:00:25 2016 debrau_c
** Last update Sun Apr 17 18:36:46 2016 debrau_c
*/

#include <lapin.h>
#include "editeur.h"

int	edit_save_next_obj_zoom(t_bunny_ini *ini,
				 char *name_zone,
				 t_edit_zone *zone)
{
  char	*value;

  if ((value = my_itoa(zone->next_zone)) == NULL)
    return (1);
  bunny_ini_set_field(ini, name_zone, "next", 0, value);
  bunny_free(value);
  bunny_ini_set_field(ini, name_zone, "obj", 0, "0");
  bunny_ini_set_field(ini, name_zone, "zoom", 0, "0");
  bunny_ini_set_field(ini, name_zone, "tol", 0, "60");
  return (0);
}

int		edit_save_nb_end(t_bunny_ini *ini,
				 char *name_zone,
				 t_edit_zone *zone)
{
  t_e_node	*tmp;
  char		*value;
  int		i;

  i = 0;
  tmp = zone->nodes;
  while (tmp != NULL)
    {
      if (tmp->end == 1)
	i++;
      tmp = tmp->next;
    }
  if ((value = my_itoa(i)) == NULL)
    return (1);
  bunny_ini_set_field(ini, name_zone, "nb_end", 0, value);
  bunny_free(value);
  return (0);
}

int	edit_save_end_start(t_bunny_ini *ini,
			    char *name_zone,
			    t_edit_zone *zone)
{
  t_e_node	*tmp;
  int		i;
  int		j;
  char		*value;

  i = 0;
  if (edit_save_nb_end(ini, name_zone, zone)) return (1);
  tmp = zone->nodes;
  j = 0;
  while (tmp != NULL)
    {
      if (tmp->end == 1 || tmp->start == 1)
	{
	  if ((value = my_itoa(tmp->index)) == NULL)
	    return (1);
	  if (tmp->end == 1)
	    bunny_ini_set_field(ini, name_zone, "end", i++, value);
	  else bunny_ini_set_field(ini, name_zone, "start", i++, value);
	  bunny_free(value);
	}
      tmp = tmp->next;
    }
  if (j == 2)
    return (1);
  return (0);
}
