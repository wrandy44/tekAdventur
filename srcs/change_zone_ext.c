/*
** change_zone_ext.c for azd in /home/debrau_c/Documents/Igraph/gfx_tekadventure
** 
** Made by debrau_c
** Login   <debrau_c@epitech.net>
** 
** Started on  Sun Apr 17 23:23:16 2016 debrau_c
** Last update Sun Apr 17 23:24:42 2016 debrau_c
*/

#include "my_inc.h"
#include "load_bmp.h"

void	change_zone_refresh_player_node(t_player *player,
					t_zone *zone,
					int node)
{
  player->current_node = node;
  player->target_node = node;
  player->path_node = node;
  player->pos.x = zone->pos_noeud[node].x - (player->rect.w / 2);
  player->pos.y = zone->pos_noeud[node].y - player->rect.h;
  player->target.x = zone->pos_noeud[node].x - (player->rect.w / 2);
  player->target.y = zone->pos_noeud[node].y - player->rect.h;
}

void	change_zone_refresh_player(t_player *player, t_zone *zone)
{
  player->current_node = zone->start;
  player->target_node = zone->start;
  player->path_node = zone->start;
  player->pos.x = zone->pos_noeud[zone->start].x - (player->rect.w / 2);
  player->pos.y = zone->pos_noeud[zone->start].y - player->rect.h;
  player->target.x = zone->pos_noeud[zone->start].x - (player->rect.w / 2);
  player->target.y = zone->pos_noeud[zone->start].y - player->rect.h;
}

t_bunny_pixelarray	*change_current_zone_fond(int nb)
{
  char			*name;
  t_bunny_pixelarray	*pix;
  int			i;

  i = 0;
  if ((name = my_strdup("pic/fond01.bmp")) == NULL)
    return (NULL);
  while (i < nb)
    {
      name[9]++;
      if (name[9] > '9')
	{
	  name[9] = '0';
	  name[8]++;
	}
      i++;
    }
  if ((pix = load_bmp(name)) == NULL)
    return (NULL);
  return (pix);
}

t_bunny_pixelarray	*change_current_zone_calc(int nb)
{
  t_bunny_pixelarray	*pix_end;
  char	*name;
  int	i;

  i = 0;
  if (nb < 0) return (NULL);
  if ((name = my_strdup("pic/calc01.bmp")) == NULL)
    return (NULL);
  while (i < nb)
    {
      name[9]++;
      if (name[9] > '9')
	{
	  name[9] = '0';
	  name[8]++;
	}
      i++;
    }
  if ((pix_end = load_bmp(name)) == NULL)
    return (NULL);
  return (pix_end);
}

int	change_zone_define_end_next(t_main_struct *mainS,
				    int *end)
{
  int	i;

  if (mainS->player.isSpawn != 0)
    return (-1);
  i = 0;
  while (i < mainS->zone[mainS->current_zone -1].nb_end)
    {
      if (mainS->player.current_node ==
	  mainS->zone[mainS->current_zone -1].end[i])
	{
	  *end = i;
	  return (0);
	}
      i++;
    }
  return (-1);
}
