/*
** zone_load.c for azd in /home/debrau_c/Documents/Igraph/gfx_tekadventure
** 
** Made by debrau_c
** Login   <debrau_c@epitech.net>
** 
** Started on  Tue Apr 12 22:05:55 2016 debrau_c
** Last update Sun Apr 17 16:32:06 2016 debrau_c
*/

#include "my_inc.h"

int	load_zone_zoom(t_zoom *zoom_z,
		       t_bunny_ini *ini,
		       const char *name_zone)
{
  char	*s;

  if ((s = my_ini_get(ini, name_zone, "zoom", 0)) == NULL)
    return (1);
  zoom_z->active = my_get_nbr(s);
  if (zoom_z->active == 0)
    return (0);
  if ((s = my_ini_get(ini, name_zone, "zoom_start", 0)) == NULL)
    return (1);
  zoom_z->start = my_get_nbr(s);
  if ((s = my_ini_get(ini, name_zone, "zoom_end", 0)) == NULL)
    return (1);
  zoom_z->end = my_get_nbr(s);
  if ((s = my_ini_get(ini, name_zone, "zoom_at_end", 0)) == NULL)
    return (1);
  zoom_z->lv_end = my_get_float(s);
  if ((s = my_ini_get(ini, name_zone, "zoom_at_start", 0)) == NULL)
    return (1);
  zoom_z->lv_start = my_get_float(s);
  return (0);
}

int	load_zone(t_zone *one_zone,
		  const char *name_ini,
		  const char *name_zone)
{
  t_bunny_ini	*new;

  if ((new = bunny_load_ini(name_ini)) == NULL)
    return (my_putstre("Fichier ini corrompue.\nArrêt Immediat.\n"));
  if (load_zone_img(one_zone, new, name_zone))
    return (1);
  if ((one_zone->chemin = zone_define_chemin(new, name_zone)) == NULL)
    return (1);
  if ((load_zone_node_and_tol(one_zone, name_zone, new)))
    return (1);
  if (load_zone_next_and_start(one_zone, new, name_zone))
    return (1);
  if ((one_zone->obj = load_zone_object(one_zone, new, name_zone)) == NULL
      && one_zone->nb_obj != 0) return (1);
  if (load_zone_zoom(&one_zone->zoom, new, name_zone)) return (1);
  bunny_delete_ini(new);
  return (0);
}
