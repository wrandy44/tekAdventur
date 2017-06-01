/*
** edit_save_ini.c for zad in /home/debrau_c/Documents/Igraph/gfx_tekadventure
** 
** Made by debrau_c
** Login   <debrau_c@epitech.net>
** 
** Started on  Fri Apr 15 23:10:04 2016 debrau_c
** Last update Sun Apr 17 16:18:08 2016 debrau_c
*/

#include <lapin.h>
#include "editeur.h"

void	edit_low_str(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (str[i] >= 'A' && str[i] <= 'Z')
	{
	  str[i] -= 'A';
	  str[i] += 'a';
	}
      i++;
    }
}

int	edit_save_ini(t_edit *data)
{
  data->control.menu_save = 1;
  edit_low_str(data->chemin_file);
  edit_save_zone(data);
  bunny_save_ini(data->ini, data->chemin_file);
  return (0);
}
