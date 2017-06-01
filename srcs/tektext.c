/*
** tektext.c for tektext in /home/debrau_c/Documents/SkillTest/chatty_2020
** 
** Made by debrau_c
** Login   <debrau_c@epitech.net>
** 
** Started on  Fri Feb 19 11:16:00 2016 debrau_c
** Last update Mon Apr 11 15:21:40 2016 debrau_c
*/

#include <lapin.h>
#include "mylapin.h"
#include "my_inc.h"

void		tekpixel3(t_bunny_pixelarray *pix,
			 t_bunny_position *pos,
			 unsigned int color)
{
  t_color	*tmp;

  tmp = (t_color *)pix->pixels;
  tmp[pos->y * pix->clipable.clip_width + pos->x].full = color;
}

unsigned int	get_color3(t_bunny_pixelarray *pix,
			  const t_bunny_position *pos)
{
  t_color	*tmp;

  tmp = (t_color *)pix->pixels;
  return (tmp[pos->y * pix->clipable.clip_width + pos->x].full);
}

void	copy_letter(t_bunny_pixelarray *pix,
		    t_bunny_pixelarray *fontpng,
		    char c,
		    t_bunny_position pos_pix)
{
  t_bunny_position	pos_font;
  int			start;

  start = pos_pix.x;
  pos_font.y = 0;
  while (pos_font.y < fontpng->clipable.clip_height)
    {
      pos_pix.x = start;
      pos_font.x = c * (fontpng->clipable.clip_width / 128);
      while (pos_font.x < (fontpng->clipable.clip_width / 128) * (c + 1))
	{
	  if (get_color3(fontpng, &pos_font) != 0xFFFFFFFF)
	    tekpixel3(pix, &pos_pix, get_color3(fontpng, &pos_font));
	  pos_pix.x++;
	  pos_font.x++;
	}
      pos_pix.y++;
      pos_font.y++;
    }
}

void	init_pos(t_bunny_position *pos_start,
		 const t_bunny_position *pos)
{
  if (pos == NULL)
    {
      pos_start->x = 0;
      pos_start->y = 0;
    }
  else
    {
      pos_start->x = pos->x;
      pos_start->y = pos->y;
    }
}

void	tektext(t_bunny_pixelarray *pix,
		t_font *font,
		const t_bunny_position *pos,
		const char *str)
{
  int	i;
  t_bunny_position	pos_start;

  i = 0;
  init_pos(&pos_start, pos);
  while (str[i])
    {
      if (str[i] != '\n')
	{
	  copy_letter(pix, font->img, str[i], pos_start);
	  pos_start.x += (font->img->clipable.clip_width / 128) + 1;
	}
      else
	{
	  pos_start.x = (pos == NULL) ? 0 : pos->x;
	  pos_start.y += 7;
	}
      i++;
    }
}
