/*
** edit_save_zone.c for zad in /home/debrau_c/Documents/Igraph/gfx_tekadventure/srcs
** 
** Made by debrau_c
** Login   <debrau_c@epitech.net>
** 
** Started on  Sun Apr 17 00:01:40 2016 debrau_c
** Last update Sun Apr 17 18:37:24 2016 debrau_c
*/

#include <lapin.h>
#include "editeur.h"

int		edit_save_chemin(t_bunny_ini *ini,
				 char *chemin,
				 char *name_zone)
{
  int		i;
  char		*value;

  i = -1;
  if (chemin == NULL)
    return (0);
  while (chemin[++i] != '\0')
    {
      if ((value = my_itoa(chemin[i])) == NULL)
	return (1);
      bunny_ini_set_field(ini, name_zone, "chemin", i, value);
      bunny_free(value);
    }
  return (0);
}

int		edit_save_node(t_bunny_ini *ini,
			       t_e_node *nodes,
			       char *name_zone)
{
  char		*value;
  int		i;
  t_e_node	*tmp;

  i = 0;
  tmp = nodes;
  while (tmp != NULL && (i = i + 1)) tmp = tmp->next;
  if ((value = my_itoa(i)) == NULL) return (1);
  bunny_ini_set_field(ini, name_zone, "nb_noeud", 0, value);
  bunny_free(value);
  tmp = nodes;
  i = 0;
  while (tmp != NULL)
    {
      if ((value = my_itoa(tmp->pos.x)) == NULL) return (1);
      bunny_ini_set_field(ini, name_zone, "pos_noeud", i++, value);
      bunny_free(value);
      if ((value = my_itoa(tmp->pos.y)) == NULL) return (1);
      bunny_ini_set_field(ini, name_zone, "pos_noeud", i++, value);
      bunny_free(value);
      tmp = tmp->next;
    }
  return (0);
}

int	edit_save_fond_calc(t_bunny_ini *ini,
			    int index_fond,
			    int index_calc,
			    char *name_zone)
{
  char	*value;

  if ((value = my_itoa(index_fond)) == NULL)
    return (1);
  bunny_ini_set_field(ini, name_zone, "fond_index", 0, value);
  bunny_free(value);
  if ((value = my_itoa(index_calc)) == NULL)
    return (1);
  bunny_ini_set_field(ini, name_zone, "calc_index", 0, value);
  bunny_free(value);
  return (0);
}

void	edit_clear_zone(t_edit_zone *zone)
{
  t_e_node	*tmp;
  t_e_node	*past;

  past = zone->nodes;
  while (past != NULL)
    {
      tmp = past->next;
      bunny_free(past);
      past = tmp;
    }
  zone->nodes = NULL;
  bunny_free(zone->chemin);
  zone->chemin = NULL;
  zone->index_fond = -1;
  zone->index_calc = -1;
}

int	edit_save_zone(t_edit *data)
{
  static int	index_zone = 0;

  bunny_ini_set_field(data->ini,
		      NULL, "nom_zone", index_zone++, data->zone.name);
  edit_save_node(data->ini, data->zone.nodes, data->zone.name);
  edit_save_fond_calc(data->ini, data->zone.index_fond,
		      data->zone.index_calc,
		      data->zone.name);
  edit_save_chemin(data->ini, data->zone.chemin, data->zone.name);
  edit_save_next_obj_zoom(data->ini, data->zone.name, &data->zone);
  edit_save_end_start(data->ini, data->zone.name, &data->zone);
  edit_clear_zone(&data->zone);
  data->zone.name[5]++;
  if (data->zone.name[5] > '9')
    {
      data->zone.name[5] = '0';
      data->zone.name[4]++;
    }
  return (0);
}
