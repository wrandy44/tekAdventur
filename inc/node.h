/*
** node.h for azd in /home/debrau_c/Documents/Igraph/gfx_tekadventure
** 
** Made by debrau_c
** Login   <debrau_c@epitech.net>
** 
** Started on  Sat Mar 26 15:36:33 2016 debrau_c
** Last update Sat Mar 26 15:37:30 2016 debrau_c
*/

#ifndef NODE_H
# define NODE_H

# include "my_inc.h"

void			node_drawing_node_with_tol(t_zone *zone,
						   t_bunny_pixelarray *fond);
void			node_drawing_node_with_tol2(const t_bunny_position *pos_node,
						    t_bunny_pixelarray *pix,
						    int tolerance);
#endif /* NODE_H */
