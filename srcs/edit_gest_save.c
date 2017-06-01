/*
** edit_gest_save.c for azd in /home/debrau_c/Documents/Igraph/gfx_tekadventure
** 
** Made by debrau_c
** Login   <debrau_c@epitech.net>
** 
** Started on  Sun Apr 17 15:31:49 2016 debrau_c
** Last update Sun Apr 17 17:43:22 2016 debrau_c
*/

#include <lapin.h>
#include "editeur.h"
#include "mylapin.h"
#include "my_realloc.h"
#include "my_string.h"

int	edit_push_letter(char *str, char c)
{
  int	i;

  i = 0;
  while (str[i]) i++;
  str[i] = c;
  str[i + 1] = '\0';
  return (0);
}

int	edit_delete_letter(char *str)
{
  int	i;

  i = 0;
  while (str[i]) i++;
  str[i - 1] = '\0';
  return (0);
}

int	edit_gest_save_file(t_edit *data,
			    t_bunny_keysym keysym)
{
  char	c;

  if (keysym >= BKS_A && keysym <= BKS_Z)
    {
      c = keysym + 65;
      if ((data->chemin_file = my_realloc(data->chemin_file,
					  my_strlen(data->chemin_file) + 2)) == NULL)
	return (1);
      edit_push_letter(data->chemin_file, c);
    }
  if (keysym == 59)
    edit_delete_letter(data->chemin_file);
  if (keysym == BKS_SPACE)
      edit_push_letter(data->chemin_file, ' ');
  if (keysym == 50)
      edit_push_letter(data->chemin_file, '.');
  return (0);
}
