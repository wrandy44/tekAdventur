/*
** init_ext.c for azd in /home/debrau_c/Documents/Igraph/gfx_tekadventure
** 
** Made by debrau_c
** Login   <debrau_c@epitech.net>
** 
** Started on  Sun Apr 17 16:57:31 2016 debrau_c
** Last update Sun Apr 17 18:37:43 2016 debrau_c
*/

#include "my_inc.h"
#include "load_bmp.h"
#include "my_string.h"

t_bankImg	*init_bank()
{
  t_bankImg	*new;
  char		*name;
  int		i;

  if ((name = my_strdup("pic/obj01.bmp")) == NULL)
    return (NULL);
  if ((new = bunny_malloc(sizeof(t_bankImg *))) == NULL)
    return (NULL);
  i = 0;
  while (i < NB_OBJECTS)
    {
      if ((new->obj[i] = load_bmp(name)) == NULL)
	return (NULL);
      name[8]++;
      if (name[8] > '9')
	{
	  name[9]++;
	  name[8] = '0';
	}
      i++;
    }
  bunny_free(name);
  return (new);
}

int	init_player_sac(t_player *player)
{
  int	i;

  i = 0;
  while (i < 5)
    {
      player->sac[i].vide = 1;
      player->sac[i].name = NULL;
      player->sac[i].index_img = -1;
      i++;
    }
  return (0);
}

int	init_player(t_player *player, t_zone *zone)
{
  if ((player->img = load_bmp("pic/kate.bmp")) == NULL)
     return (1);
  player->isSpawn = 1;
  player->rect.w = 35;
  player->rect.h = 50;
  player->current_node = 0;
  player->target_node = 0;
  player->path_node = 0;
  player->rect.x = 0;
  player->rect.y = 0;
  player->pos.x = zone->pos_noeud[zone->start].x - (player->rect.w / 2);
  player->pos.y = zone->pos_noeud[zone->start].y - player->rect.h;
  player->target.x = player->pos.x;
  player->target.y = player->pos.y;
  init_player_sac(player);
  return (0);
}

t_zone		*init_all_zone(const char *name_file, t_main_struct *mainS)
{
  t_bunny_ini	*ini;
  char		*get;
  int		i;
  int		max;
  t_zone	*all_zone;

  if ((ini = bunny_load_ini(name_file)) == NULL)
    return (NULL);
  max = my_ini_count_member(ini, NULL, "nom_zone");
  if ((all_zone = bunny_malloc(max * sizeof(t_zone))) == NULL)
    return (NULL);
  i = -1;
  while (++i < max)
    {
      if ((get = my_ini_get(ini, NULL, "nom_zone", i)) == NULL)
	return (NULL);
      if (load_zone(&all_zone[i], name_file, get))
	return (NULL);
    }
  mainS->nb_zone = max;
  return (all_zone);
}
