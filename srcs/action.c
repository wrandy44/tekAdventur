/*
** action.c for zd in /home/debrau_c/Documents/Igraph/gfx_tekadventure
** 
** Made by debrau_c
** Login   <debrau_c@epitech.net>
** 
** Started on  Wed Mar 30 06:34:33 2016 debrau_c
** Last update Sun Apr 17 17:34:56 2016 debrau_c
*/

#include "my_inc.h"

int	action_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  while (s1[i] == s2[i] && s1[i] && s2[i])
    i++;
  if (s1[i] == '\0')
    return (1);
  return (0);
}

int	action_ramasser_ext(t_player *player,
			    t_object *obj,
			    t_main_struct *mainS)
{
  int	i;

  i = 0;
  while (i < 5 && !player->sac[i].vide)
    i++;
  if (i == 4) return (1);
  msg_anim_rammassage(mainS->screen, mainS->font, obj->name);
  player->sac[i].vide = 0;
  player->sac[i].name = obj->name;
  player->sac[i].index_img = 0;
  obj->exist = 0;
  return (0);
}

int	action_ramasser(t_player *player,
			t_zone *zone, t_main_struct *mainS)
{
  int	node;
  int	i;

  node = player->current_node;
  i = 0;
  while (i < zone->nb_obj)
    {
      if (zone->obj[i].exist && zone->obj[i].event_node == node)
	{
	  if (action_strcmp("ramasser", zone->obj[i].event_type))
	    action_ramasser_ext(player, &zone->obj[i], mainS);
	}
      i++;
    }
  return (0);
}
