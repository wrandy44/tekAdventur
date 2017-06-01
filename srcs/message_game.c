/*
** message_game.c for azd in /home/debrau_c/Documents/Igraph/gfx_tekadventure
** 
** Made by debrau_c
** Login   <debrau_c@epitech.net>
** 
** Started on  Wed Mar 30 21:41:11 2016 debrau_c
** Last update Sun Apr 17 16:56:32 2016 debrau_c
*/

#include <lapin.h>
#include "load_bmp.h"
#include "mylapin.h"
#include "my_inc.h"

int			count_str_y(t_bunny_pixelarray *font,
				    char *str)
{
  int			i;
  int			res;

  i = 0;
  while (str[i]) i++;
  res = i * (font->clipable.clip_width / 128);
  return (res);
}

void			msg_anim_rammassage_draw(t_bunny_pixelarray *pix,
						 t_bunny_pixelarray *font,
						 char *txt,
						 char *object)
{
  static int		i = 1;
  static int		j = 0;
  char			new[19];
  char			new_2[19];
  t_bunny_position	pos;
  t_font		font_s;

  if (++j > 100)
    {
      j = 0;
      i++;
    }
  font_s.img = font;
  font_s.size = 1;
  pos.x = pos.y = 20;
  my_strncpy(txt, new, i);
  my_bunny_fill(pix, 0xFFA8E754);
  tektext(pix, &font_s, &pos, new);
  if (object != NULL)
    {
      pos.y += font->clipable.clip_height;
      my_strncpy(object, new_2, i - 19);
      tektext(pix, &font_s, &pos, new_2);
    }
}

int			msg_anim_rammassage(t_bunny_window *win,
					    t_bunny_pixelarray *font,
					    char *object)
{
  t_bunny_pixelarray	*pix;
  t_bunny_position	pos;
  int			i;

  if ((pix = load_bmp("pic/textbox.bmp")) == NULL)
    return (1);
  pos.x = (SCREEN_W / 2) - (pix->clipable.clip_width / 2);
  pos.y = 20;
  i = 0;
  while (i < 5000)
    {
      msg_anim_rammassage_draw(pix, font, "Vous avez ramasse :", object);
      bunny_blit(&win->buffer, &pix->clipable, &pos);
      bunny_display(win);
      i++;
    }
  bunny_delete_clipable(&pix->clipable);
  return (0);
}

int		msg_anim_ouvrir(t_bunny_window *win,
				t_bunny_pixelarray *font,
				char *object)
{
  t_bunny_pixelarray	*pix;
  t_bunny_position	pos;
  int			i;

  if ((pix = load_bmp("pic/textbox.bmp")) == NULL)
    return (1);
  pos.x = (SCREEN_W / 2) - (pix->clipable.clip_width / 2);
  pos.y = 20;
  i = 0;
  while (i < 5000)
    {
      msg_anim_rammassage_draw(pix, font, "Vous tentez d'ouvrir :", object);
      bunny_blit(&win->buffer, &pix->clipable, &pos);
      bunny_display(win);
      i++;
    }
  bunny_delete_clipable(&pix->clipable);
  return (0);
}

int	message_anim(t_bunny_window *win,
		     t_bunny_pixelarray *font,
		     char *message)
{
  t_bunny_pixelarray	*pix;
  t_bunny_position	pos;
  int			i;
  t_font		font_s;

  font_s.img = font;
  font_s.size = 1;
  if ((pix = load_bmp("pic/textbox.bmp")) == NULL)
    return (1);
  pos.x = (SCREEN_W / 2) - (pix->clipable.clip_width / 2);
  pos.y = 20;
  i = 0;
  while (i < 5000)
    {
      message_anim_ext(pix, &font_s, message, i);
      bunny_blit(&win->buffer, &pix->clipable, &pos);
      bunny_display(win);
      i++;
    }
  bunny_delete_clipable(&pix->clipable);
  return (0);
}
