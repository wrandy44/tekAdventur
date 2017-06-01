/*
** tekpixel.c for tekpixel in /home/debrau_c/FUN/LibLapin/TryINI
** 
** Made by Carl DEBRAUWERE
** Login   <debrau_c@epitech.net>
** 
** Started on  Thu Nov 19 17:32:54 2015 Carl DEBRAUWERE
** Last update Sun Apr  3 13:34:38 2016 debrau_c
*/

#include <lapin.h>

void		tekpixel(t_bunny_pixelarray *pix,
			 t_bunny_position *pos,
			 unsigned int color)
{
  t_color	*tmp;

  tmp = (t_color *)pix->pixels;
  tmp[pos->y * pix->clipable.clip_width + pos->x].full = color;
}

unsigned int	get_color(t_bunny_pixelarray *img, t_bunny_position *pos)
{
  unsigned int	color;
  t_color	*pixeltab;

  pixeltab = (t_color *)img->pixels;
  color = pixeltab[pos->y * img->clipable.clip_width + pos->x].full;
  return (color);
}
