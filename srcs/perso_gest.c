/*
** perso_gest.c for perso_gest in /home/debrau_c/Documents/Igraph/gfx_tekadventure/srcs
** 
** Made by debrau_c
** Login   <debrau_c@epitech.net>
** 
** Started on  Wed Mar  2 16:37:26 2016 debrau_c
** Last update Sun Apr 17 23:25:06 2016 debrau_c
*/

#include <math.h>
#include "my_inc.h"

void		change_current_node(t_player *player, t_zone *zone)
{
  int		i;
  t_bunny_position	tmp_p;
  t_bunny_position	tmp_n;
  int		my_tol;

  my_tol = zone->tolerance / 2;
  tmp_p.x = player->pos.x + (player->rect.w / 2);
  tmp_p.y = player->pos.y + player->rect.h;
  i = -1;
  while (++i < zone->nb_noeud)
    {
      tmp_n = zone->pos_noeud[i];
      if (tmp_p.x > tmp_n.x - my_tol && tmp_p.x < tmp_n.x + my_tol
	  && tmp_p.y > tmp_n.y - my_tol && tmp_p.y < tmp_n.y + my_tol)
	{
	  if (player->current_node != i)
	    {
	      player->target.x = player->pos.x;
	      player->target.y = player->pos.y;
	      player->isSpawn = 0;
	    }
	  player->current_node = i;
	}
    }
}

int		anim_player(t_player *player, int i)
{
  if (i == 3)
    {
      if (player->rect.x == player->rect.w * 6)
	player->rect.x = 0;
      else
	player->rect.x += player->rect.w;
      i = 0;
    }
  if (player->orientation == DROITE)
    player->rect.y = 110;
  else if (player->orientation == GAUCHE)
    player->rect.y = 165;
  else if (player->orientation == BAS)
    player->rect.y = 0;
  else if (player->orientation == HAUT)
    player->rect.y = 55;
  return (i);
}

int		perso_define_next_node(t_player *player,
					 t_zone *zone)
{
  int		i;
  int		j;
  int		min;
  int		res;

  min = my_strlen(zone->chemin);
  i = -1;
  while (zone->chemin[++i])
    if (zone->chemin[i] == player->current_node + 1)
      {
	j = 0;
	while (zone->chemin[j + i]
	       && zone->chemin[j + i] != player->target_node + 1)
	  j++;
	if (zone->chemin[j + i] == player->target_node + 1 && min > j)
	  {
	    min = j;
	    res = i;
	  }
      }
  return (res + 1);
}

void		perso_define_next_target(t_player *player,
					 t_zone *zone)
{
  int	next_pos;

  if (player->target_node == player->current_node)
    return ;
  next_pos = perso_define_next_node(player, zone);
  player->path_node = zone->chemin[next_pos] - 1;
  player->target.x =
    zone->pos_noeud[player->path_node].x - (player->rect.w / 2);
  player->target.y =
    zone->pos_noeud[player->path_node].y - player->rect.h;
}

void		perso_coef_directeur_init(t_bunny_position *current,
					  t_bunny_position *next,
					  t_bunny_rect rect)
{
  next->x = current->x - rect.w;
  next->y = current->y - rect.h;
}
