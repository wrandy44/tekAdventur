/*
** edit_draw_ext.c for azd in /home/debrau_c/Documents/Igraph/gfx_tekadventure
** 
** Made by debrau_c
** Login   <debrau_c@epitech.net>
** 
** Started on  Sun Apr 17 17:22:12 2016 debrau_c
** Last update Sun Apr 17 17:54:35 2016 debrau_c
*/

#include <lapin.h>
#include "mylapin.h"
#include "editeur.h"
#include "load_bmp.h"
#include "my_string.h"

void			edit_draw_chemin(t_bunny_pixelarray *fond,
					 t_e_node *nodes,
					 char *chemin)
{
  int			i;
  t_bunny_position	pos[2];
  t_e_node		*tmp;

  i = 0;
  if (chemin == NULL) return ;
  while (chemin[i])
    {
      i++;
      tmp = nodes;
      while (tmp != NULL && chemin[i] != '\0' && tmp->index != chemin[i] -1)
	tmp = tmp->next;
      if (chemin[i] == '\0') return ;
      pos[0] = tmp->pos;
      tmp = nodes;
      while (tmp != NULL && tmp->index != chemin[i -1] -1)
	tmp = tmp->next;
      pos[1] = tmp->pos;
      tekline(fond, pos, RED);
    }
}

void			edit_draw_node(t_e_node *nodes,
				       int index_first_node,
				       t_bunny_pixelarray *fond)
{
  t_e_node		*tmp;

  tmp = nodes;
  while (tmp != NULL)
    {
      if (tmp->start == 1)
	teksquare(fond, tmp->pos, 40, YELLOW);
      else if (tmp->end == 1)
	teksquare(fond, tmp->pos, 40, GREEN);
      else
	teksquare(fond, tmp->pos, 40, BLUE);
      if (tmp->index == index_first_node)
	teksquare(fond, tmp->pos, 40, RED);
      tmp = tmp->next;
    }
}

void			edit_draw_calc(t_bunny_pixelarray *fond,
				       int index)
{
  t_bunny_pixelarray	*tmp;
  char			*name;

  if ((name = my_strdup("pic/calc01.bmp")) == NULL)
    return ;
  while (index > 0)
    {
      name[9]++;
      if (name[9] > '9')
	{
	  name[9] = '0';
	  name[8]++;
	}
      index--;
    }
  if ((tmp = load_bmp(name)) == NULL)
    return ;
  my_alpha_blit(fond, tmp, NULL, NULL);
  bunny_delete_clipable(&tmp->clipable);
}

void			edit_draw_fond(t_bunny_pixelarray *fond,
				       int index)
{
  t_bunny_pixelarray	*tmp;
  char			*name;

  if ((name = my_strdup("pic/fond01.bmp")) == NULL)
    return ;
  while (index > 0)
    {
      name[9]++;
      if (name[9] > '9')
	{
	  name[9] = '0';
	  name[8]++;
	}
      index--;
    }
  if ((tmp = load_bmp(name)) == NULL)
    return ;
  my_alpha_blit(fond, tmp, NULL, NULL);
  bunny_delete_clipable(&tmp->clipable);
}
