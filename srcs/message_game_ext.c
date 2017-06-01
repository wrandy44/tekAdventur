/*
** message_game_ext.c for zad in /home/debrau_c/Documents/Igraph/gfx_tekadventure
** 
** Made by debrau_c
** Login   <debrau_c@epitech.net>
** 
** Started on  Sun Apr 17 16:56:06 2016 debrau_c
** Last update Sun Apr 17 17:54:35 2016 debrau_c
*/

#include <lapin.h>
#include "load_bmp.h"
#include "mylapin.h"
#include "my_inc.h"

int	message_anim_ext(t_bunny_pixelarray *pix,
			 t_font *font,
			 char *message,
			 int nb_frame)
{
  int			j;
  char			new[255];
  t_bunny_position	pos2;

  pos2.x = pos2.y = 10;
  j = nb_frame / 200;
  my_strncpy(message, new, j);
  tektext(pix, font, &pos2, new);
  return (0);
}
