/*
** editeur.c for azd in /home/debrau_c/Documents/Igraph/gfx_tekadventure
** 
** Made by debrau_c
** Login   <debrau_c@epitech.net>
** 
** Started on  Fri Apr 15 14:53:27 2016 debrau_c
** Last update Sat Apr 16 20:30:03 2016 debrau_c
*/

#include <lapin.h>
#include "mylapin.h"
#include "editeur.h"

void	edit_free(t_edit *data)
{
  bunny_delete_clipable(&data->fond->clipable);
}

int		editeur()
{
  t_edit	data;

  if (edit_init(&data))
    return (1);
  bunny_set_click_response(&edit_mouse);
  bunny_set_key_response(&edit_keyset);
  bunny_set_loop_main_function(&edit_loop);
  bunny_loop(data.screen, 60, &data);
  return (0);
}
