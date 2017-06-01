/*
** tekline.c for tekline in /home/debrau_c/Documents/Igraph/gfx_tekadventure/srcs
** 
** Made by debrau_c
** Login   <debrau_c@epitech.net>
** 
** Started on  Wed Mar  2 00:36:57 2016 debrau_c
** Last update Mon Apr  4 14:58:30 2016 debrau_c
*/

#include "mylapin.h"

float	calc_coef(t_bunny_position *pos)
{
  float	coef;

  coef = ((float)pos[1].y - (float)pos[0].y);
  coef /= ((float)pos[1].x - (float)pos[0].x);
  return (coef);
}

float	calc_b(t_bunny_position *pos,
	       float coef)
{
  float	b;

  b = (float)pos[0].y - (coef * (float)pos[0].x);
  return (b);
}

void	easy_draw(t_bunny_pixelarray *pix,
		  t_bunny_position *pos,
		  unsigned int col)
{
  int	value;
  t_bunny_position	pos_tmp;

  pos_tmp.x = pos[0].x;
  pos_tmp.y = pos[0].y;
  if (pos[0].x == pos[1].x)
    {
      value = (pos[0].y < pos[1].y) ? 1 : -1;
      while (pos_tmp.y != pos[1].y)
	{
	  tekpixel(pix, &pos_tmp, col);
	  pos_tmp.y += value;
	}
      return ;
    }
  value = (pos[0].x < pos[1].x) ? 1 : -1;
  while (pos_tmp.x != pos[1].x)
    {
      tekpixel(pix, &pos_tmp, col);
      pos_tmp.x += value;
    }
}

void			init_all(t_bunny_position *pos_tmp,
				 t_bunny_position *pos,
				 float *b,
				 float *coef)
{
  pos_tmp->x = pos[0].x;
  pos_tmp->y = pos[0].y;
  *coef = calc_coef(pos);
  *b = calc_b(pos, *coef);
}

void			tekline(t_bunny_pixelarray *pix,
				t_bunny_position *pos,
				unsigned int color)
{
  float			coef;
  float			b;
  t_bunny_position	pos_tmp;
  t_bunny_position	pos_moove;

  if (pos[0].x == pos[1].x || pos[0].y == pos[1].y)
    easy_draw(pix, pos, color);
  else
    {
      init_all(&pos_tmp, pos, &b, &coef);
      while (pos_tmp.x != pos[1].x + 1)
	{
	  tekpixel(pix, &pos_tmp, color);
	  pos_moove = pos_tmp;
	  pos_tmp.y = coef * pos_tmp.x + b;
	  pos_tmp.x += (pos[0].x < pos[1].x) ? 1 : -1;
	  while (pos_moove.y != pos_tmp.y)
	    {
	      tekpixel(pix, &pos_moove, color);
	      pos_moove.y += (pos_moove.y <= pos_tmp.y) ? 1 : -1;
	    }
	}
    }
}
