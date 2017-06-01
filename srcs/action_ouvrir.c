/*
** action_ouvrir.c for zad in /home/debrau_c/Documents/Igraph/gfx_tekadventure
** 
** Made by debrau_c
** Login   <debrau_c@epitech.net>
** 
** Started on  Sat Apr 16 19:08:21 2016 debrau_c
** Last update Sun Apr 17 18:35:57 2016 debrau_c
*/

#include <lapin.h>
#include "my_inc.h"

int	action_ouvrir(t_player *player,
		      t_zone *zone,
		      t_main_struct *mainS)
{
  int	node;
  int	i;
  char	*new;

  node = player->current_node;
  i = -1;
  while (++i < 5 && !player->sac[i].vide)
    if (my_strcmp("clef jaune", player->sac[i].name) == 0
	&& my_strcmp("porte jaune", zone->obj[0].name) == 0
	&& zone->obj[0].event_node == node)
      {
	if ((new = my_strdup2("Vous ouvrez :", zone->obj[0].name)) == NULL)
	  return (1);
	zone->obj[0].block = 0;
	zone->obj[0].exist = 0;
	bunny_free(player->sac[i].name);
	player->sac[i].vide = 1;
	message_anim(mainS->screen, mainS->font, new);
	bunny_free(new);
	return (0);
      }
  message_anim(mainS->screen, mainS->font, "Rien ne se passe\n");
  return (0);
}
