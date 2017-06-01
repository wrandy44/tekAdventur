/*
** zone_gest.c for azd in /home/debrau_c/Documents/Igraph/gfx_tekadventure/srcs
** 
** Made by debrau_c
** Login   <debrau_c@epitech.net>
** 
** Started on  Wed Mar  2 13:43:15 2016 debrau_c
** Last update Sun Apr 17 18:33:32 2016 debrau_c
*/

#include "my_inc.h"

float	zone_get_zoom(t_zone *one_zone, t_bunny_position pos)
{
  t_zoom	*zoom;
  int		real;
  float		zoomi;
  float		coef;

  zoom = &one_zone->zoom;
  if (zoom->active == 0) return (1.5);
  if (pos.y < zoom->end)
    return (zoom->lv_end);
  if (pos.y > zoom->start)
    return (zoom->lv_start);
  else
    {
      real = zoom->end - zoom->start;
      zoomi = zoom->lv_end - zoom->lv_start;
      coef = (float)pos.y / real;
    }
  return (coef * zoomi);
}

int	zone_recup_noeud(t_bunny_ini *new,
			 t_zone *one_zone,
			 const char *name_zone)
{
  char	*get;
  int	i;
  int	res;
  int	j;

  i = 0;
  if ((one_zone->pos_noeud =
       bunny_malloc(sizeof(t_bunny_position) * one_zone->nb_noeud)) == NULL)
    return (1);
  j = 0;
  while (i < one_zone->nb_noeud * 2)
    {
      if ((get = my_ini_get(new, name_zone, "pos_noeud", i)) == NULL)
	return (1);
      res = my_get_nbr(get);
      if (i % 2 == 0)
	one_zone->pos_noeud[j].x = res;
      else
	{
	  one_zone->pos_noeud[j].y = res;
	  j++;
	}
      i++;
    }
  return (0);
}

char	*zone_define_chemin(const t_bunny_ini *new,
			    const char *name_zone)
{
  int	taille_chemin;
  char	*chemin;
  char	*s;
  int	i;

  i = 0;
  taille_chemin = my_ini_count_member(new, name_zone, "chemin");
  if ((chemin = bunny_malloc(sizeof(char) * (taille_chemin + 1))) == NULL)
    return (NULL);
  while (i < taille_chemin)
    {
      if ((s = my_ini_get(new, name_zone, "chemin", i)) == NULL)
	return (NULL);
      chemin[i] = my_get_nbr(s);
      i++;
    }
  chemin[i] = '\0';
  return (chemin);
}

int	load_zone_img(t_zone *one_zone,
		       const t_bunny_ini *ini,
		       const char *name_zone)
{
  char	*get;

  if ((get = my_ini_get(ini, name_zone, "fond_index", 0)) == NULL)
    return (1);
  one_zone->fond_index = my_get_nbr(get);
  if ((get = my_ini_get(ini, name_zone, "calc_index", 0)) == NULL)
    return (1);
  one_zone->calc_index = my_get_nbr(get);
  return (0);
}
