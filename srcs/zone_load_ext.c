/*
** zone_load_ext.c for azd in /home/debrau_c/Documents/Igraph/gfx_tekadventure
** 
** Made by debrau_c
** Login   <debrau_c@epitech.net>
** 
** Started on  Sun Apr 17 16:19:07 2016 debrau_c
** Last update Sun Apr 17 18:34:01 2016 debrau_c
*/

#include "my_inc.h"

int	load_zone_node_and_tol(t_zone *zone,
			       const char *name_zone,
			       t_bunny_ini *ini)
{
  char	*get;

  if ((get = my_ini_get(ini, name_zone, "nb_noeud", 0)) == NULL)
    return (1);
  zone->nb_noeud = my_get_nbr(get);
  if (zone_recup_noeud(ini, zone, name_zone))
    return (1);
  if ((get = my_ini_get(ini, name_zone, "tol", 0)) == NULL)
   return (1);
  zone->tolerance = my_get_nbr(get);
  return (0);
}

int	load_zone_catch_all_end_next(t_zone *zone, t_bunny_ini *ini,
				     const char *name)
{
  int	i;
  char	*s;

  i = 0;
  if ((zone->end =
       bunny_malloc(sizeof(int) * zone->nb_end)) == NULL) return (1);
  if ((zone->next =
       bunny_malloc(sizeof(int) * zone->nb_end)) == NULL) return (1);
  if ((zone->end_defined_node =
       bunny_malloc(sizeof(int) * zone->nb_end)) == NULL)
    return (1);
  while (i < zone->nb_end)
    {
      if ((s = my_ini_get(ini, name, "end", i)) == NULL)
	return (1);
      zone->end[i] = my_get_nbr(s);
      if ((s = my_ini_get(ini, name, "next", i)) == NULL)
	return (1);
      zone->next[i] = my_get_nbr(s);
      if ((s = my_ini_get(ini, name, "end_defined_node", i)) == NULL)
	zone->end_defined_node[i] = -1;
      else zone->end_defined_node[i] = my_get_nbr(s);
      i++;
    }
  return (0);
}

int	load_zone_next_and_start(t_zone *zone,
				 t_bunny_ini *ini,
				 const char *name_zone)
{
  char	*get;

  if ((get = my_ini_get(ini, name_zone, "start", 0)) == NULL) return (1);
  zone->start = my_get_nbr(get);
  if ((get = my_ini_get(ini, name_zone, "nb_end", 0)) == NULL) return (1);
  zone->nb_end = my_get_nbr(get);
  if (load_zone_catch_all_end_next(zone, ini, name_zone))
    return (1);
  return (0);
}

int		load_zone_object_ext(t_bunny_ini *ini,
				     const char *name_zone,
				     t_object *new,
				     int i)
{
  char		*s;

  if ((s = my_ini_get(ini, name_zone, "obj_pos", i * 2 + 1)) == NULL)
    return (1);
  new[i].pos.y = my_get_nbr(s);
  if ((s = my_ini_get(ini, name_zone, "obj_event_node", i)) == NULL)
    return (1);
  new[i].event_node = my_get_nbr(s);
  if ((s = my_ini_get(ini, name_zone, "obj_event_type", i)) == NULL)
    return (1);
  if ((new[i].event_type = my_strdup(s)) == NULL)
    return (1);
  if ((s = my_ini_get(ini, name_zone, "obj_pix_index", i)) == NULL)
    return (1);
  new[i].pix_index = my_get_nbr(s);
  if ((s = my_ini_get(ini, name_zone, "obj_block", i)) == NULL)
    return (1);
  new[i].block = my_get_nbr(s);
  return (0);
}

t_object	*load_zone_object(t_zone *one_zone,
				  t_bunny_ini *ini,
				  const char *name_zone)
{
  char	*s;
  int	i;
  t_object	*new;

  one_zone->nb_obj = 0;
  if ((s = my_ini_get(ini, name_zone, "obj", 0)) == NULL) return (NULL);
  if (s[0] == '0' && s[1] == '\0') return (NULL);
  else one_zone->nb_obj = my_get_nbr(s);
  if ((new = bunny_malloc(sizeof(t_object) * one_zone->nb_obj)) == NULL)
    return (NULL);
  i = -1;
  while (++i < one_zone->nb_obj)
    {
      new[i].exist = 1;
      if ((s = my_ini_get(ini, name_zone, "obj_name", i)) == NULL)
	return (NULL);
      if ((new[i].name = my_strdup(s)) == NULL) return (NULL);
      if ((s = my_ini_get(ini, name_zone, "obj_pos", i * 2)) == NULL)
	return (NULL);
      new[i].pos.x = my_get_nbr(s);

      if (load_zone_object_ext(ini, name_zone, new, i)) return (NULL);
    }
  return (new);
}
