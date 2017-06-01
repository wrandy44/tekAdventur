/*
** change_zone.c for azd in /home/debrau_c/Documents/Igraph/gfx_tekadventure
** 
** Made by debrau_c
** Login   <debrau_c@epitech.net>
** 
** Started on  Wed Mar 30 01:30:35 2016 debrau_c
** Last update Sun Apr 17 23:23:40 2016 debrau_c
*/

#include "my_inc.h"
#include "load_bmp.h"

int	change_zone_block_node(t_main_struct *mainS)
{
  int	curr_node;
  int	curr_zone;
  int	i;

  i = 0;
  curr_node = mainS->player.current_node;
  curr_zone = mainS->current_zone - 1;
  while (i < mainS->zone[curr_zone].nb_obj)
    {
      if (mainS->zone[curr_zone].obj[i].event_node == curr_node
	  && mainS->zone[curr_zone].obj[i].block == 1)
	return (1);
      i++;
    }
  return (0);
}

void	change_zone_ext(t_main_struct *mainS, int curr)
{
  if (mainS->current_zone_calc != NULL)
    bunny_delete_clipable(&mainS->current_zone_calc->clipable);
  mainS->current_zone_calc =
    change_current_zone_calc(mainS->zone[curr].calc_index);
  mainS->player.isSpawn = 1;
}

int	change_zone(t_main_struct *mainS)
{
  int	curr;
  int	last;
  int	k;

  if (change_zone_block_node(mainS)) return (0);
  if (change_zone_define_end_next(mainS, &k) == -1) curr = -1;
  else if (mainS->player.current_node ==
	   mainS->zone[mainS->current_zone -1].end[k] && !mainS->player.isSpawn)
    {
      last = mainS->current_zone - 1;
      mainS->current_zone = mainS->zone[mainS->current_zone -1].next[k];
      if (mainS->current_zone > mainS->nb_zone) return (1);
      curr = mainS->current_zone - 1;
      if (mainS->zone[last].end_defined_node[k] != -1)
	change_zone_refresh_player_node(&mainS->player, &mainS->zone[curr],
					mainS->zone[last].end_defined_node[k]);
      else change_zone_refresh_player(&mainS->player, &mainS->zone[curr]);
      bunny_delete_clipable(&mainS->current_zone_fond->clipable);
      if ((mainS->current_zone_fond = change_current_zone_fond(curr)) == NULL)
	return (my_putstre("No image fond\n"));
      change_zone_ext(mainS, curr);
    }
  return (0);
}
