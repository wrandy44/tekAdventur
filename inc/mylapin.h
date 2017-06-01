/*
** mylapin.h for myLapnzef in /home/debrau_c/bin/new_repo_info
** 
** Made by debrau_c
** Login   <debrau_c@epitech.net>
** 
** Started on  Fri Feb 19 11:38:31 2016 debrau_c
** Last update Sat Apr 16 13:12:06 2016 debrau_c
*/

#ifndef MY_LAPIN_H
# define MY_LAPIN_H

# include <lapin.h>

typedef struct		s_font
{
  t_bunny_pixelarray	*img;
  int			size;
}			t_font;

typedef struct	s_bunny_rect
{
  int		x;
  int		y;
  int		w;
  int		h;
}		t_bunny_rect;

void		tekpixel(t_bunny_pixelarray *pix,
			 t_bunny_position *pos,
			 unsigned int color);
int		my_bunny_fill(t_bunny_pixelarray *img,
			      unsigned int color);
void		tekline(t_bunny_pixelarray *pix,
			t_bunny_position *pos,
			unsigned int color);
unsigned int	get_color(t_bunny_pixelarray *img,
			  t_bunny_position *pos);
void		my_alpha_blit(t_bunny_pixelarray *win,
			      t_bunny_pixelarray *pix,
			      t_bunny_position *pos,
			      t_bunny_rect *rect);
char		*my_ini_get(const t_bunny_ini *ini,
			    const char *sc,
			    const char *fi,
			    const int i);
int		my_ini_count_member(const t_bunny_ini *ini,
				    const char *sc,
				    const char *fi);
void		tektext(t_bunny_pixelarray *pix, t_font *font,
			const t_bunny_position *pos, const char *str);
void		teksquare(t_bunny_pixelarray *pix,
			  t_bunny_position middle,
			  int size,
			  unsigned int color);

#endif /* MY_LAPIN_H */
