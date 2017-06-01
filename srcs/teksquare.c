/*
** teksquare.c for zad in /home/debrau_c/Documents/Igraph/gfx_tekadventure
** 
** Made by debrau_c
** Login   <debrau_c@epitech.net>
** 
** Started on  Sat Apr 16 13:05:23 2016 debrau_c
** Last update Sat Apr 16 19:32:46 2016 debrau_c
*/

#include <lapin.h>
#include "mylapin.h"

void	teksquare(t_bunny_pixelarray *pix,
		  t_bunny_position middle,
		  int size,
		  unsigned int color)
{
  t_bunny_position	draw;

  draw.x = middle.x - (size / 2);
  draw.y = middle.y - (size / 2);
  while (++draw.x < middle.x + size / 2)
    tekpixel(pix, &draw, color);
  while (++draw.y < middle.y + size / 2)
    tekpixel(pix, &draw, color);
  draw.x = middle.x - (size / 2);
  draw.y = middle.y - (size / 2);
  while (++draw.y < middle.y + size / 2)
    tekpixel(pix, &draw, color);
  while (++draw.x < middle.x + size / 2)
    tekpixel(pix, &draw, color);
}
