/*
** node_gest.c for ada in /home/debrau_c/Documents/Igraph/gfx_tekadventure
** 
** Made by debrau_c
** Login   <debrau_c@epitech.net>
** 
** Started on  Sat Mar 26 15:26:19 2016 debrau_c
** Last update Wed Mar 30 05:45:31 2016 debrau_c
*/

#include "my_inc.h"
#include "mylapin.h"

void			node_drawing_chemin(t_zone *zone,
					    t_bunny_pixelarray *pix)
{
  int			i;
  t_bunny_position	pos[2];

  i = 1;
  while (zone->chemin[i])
    {
      pos[0].x = zone->pos_noeud[(int)zone->chemin[i - 1] - 1].x;
      pos[0].y = zone->pos_noeud[(int)zone->chemin[i - 1] - 1].y;
      pos[1].x = zone->pos_noeud[(int)zone->chemin[i] - 1].x;
      pos[1].y = zone->pos_noeud[(int)zone->chemin[i] - 1].y;
      tekline(pix, pos, RED);
      i++;
    }
}

void			node_drawing_node_with_tol2(const t_bunny_position *pos_node,
						    t_bunny_pixelarray *pix,
						    int tolerance)
{
  t_bunny_position	pos;

  pos.x = pos_node->x - tolerance - 1;
  pos.y = pos_node->y - tolerance;
  while (++pos.x < (pos_node->x + tolerance))
    tekpixel(pix, &pos, RED);
  pos.y = pos_node->y + tolerance;
  pos.x = pos_node->x - tolerance - 1;
  while (++pos.x < (pos_node->x + tolerance))
    tekpixel(pix, &pos, RED);
  pos.x = pos_node->x - tolerance;
  pos.y = pos_node->y - tolerance - 1;
  while (++pos.y < (pos_node->y + tolerance))
    tekpixel(pix, &pos, RED);
  pos.x = pos_node->x + tolerance;
  pos.y = pos_node->y - tolerance - 1;
  while (++pos.y < (pos_node->y + tolerance))
    tekpixel(pix, &pos, RED);
}

void			node_drawing_node_with_tol(t_zone *zone,
						   t_bunny_pixelarray *fond)
{
  int			i;

  i = 0;
  while (i < zone->nb_noeud)
    {
      node_drawing_node_with_tol2(&zone->pos_noeud[i], fond, zone->tolerance);
      i++;
    }
  node_drawing_chemin(zone, fond);
}

int			node_check_click_to_node(const t_bunny_position  *mouse_pos,
						 t_zone *zone)
{
  t_bunny_position	pos;
  int			i;

  i = 0;
  while (i < zone->nb_noeud)
    {
      pos.x = zone->pos_noeud[i].x;
      pos.y = zone->pos_noeud[i].y;
      if ((mouse_pos->x > (pos.x - zone->tolerance)
	   && mouse_pos->x < (pos.x + zone->tolerance))
	  && (mouse_pos->y > (pos.y - zone->tolerance)
	      && mouse_pos->y < (pos.y + zone->tolerance)))
	return (i);
      i++;
    }
  return (-1);
}
