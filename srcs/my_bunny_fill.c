/*
** my_bunny_fill.c for my_bunny_fill in /home/debrau_c/FUN/LibLapin/TryINI/CLEAN
** 
** Made by Carl DEBRAUWERE
** Login   <debrau_c@epitech.net>
** 
** Started on  Fri Nov 20 16:38:19 2015 Carl DEBRAUWERE
** Last update Fri Feb 19 11:39:53 2016 debrau_c
*/

#include <lapin.h>
#include "mylapin.h"

int	my_bunny_fill(t_bunny_pixelarray *img, unsigned int color)
{
  int	i;
  int	j;
  t_bunny_position pos;

  i = 0;
  j = 0;
  while (i < img->clipable.clip_width)
    {
      pos.x = i;
      j = 0;
      while (j < img->clipable.clip_height)
	{
	  pos.y = j++;
	  tekpixel(img, &pos, color);
	}
      i++;
    }
  return (0);
}
