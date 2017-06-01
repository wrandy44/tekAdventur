/*
** perso_gest_ext.c for azd in /home/debrau_c/Documents/Igraph/gfx_tekadventure
** 
** Made by debrau_c
** Login   <debrau_c@epitech.net>
** 
** Started on  Sun Apr 17 16:32:45 2016 debrau_c
** Last update Sun Apr 17 16:34:52 2016 debrau_c
*/

#include <math.h>
#include "my_inc.h"

void		perso_coef_directeur_init_coef_b(t_bunny_position pos1,
						 t_bunny_position pos2,
						 float *coef,
						 float *b)
{
  *coef = ((float)pos2.y) - ((float)pos1.y);
  *coef /= ((float)pos2.x) - ((float)pos1.x);
  *b = (float)pos1.y - (*coef * (float)pos1.x);
}

void		perso_maj_pos(t_bunny_position *current,
			      float *stack_x,
			      float *stack_y)
{
  int		convert;
  int		isneg;

  isneg = 0;
  if (*stack_x > 1 || *stack_x < -1)
    {
      if (*stack_x < 0 && (isneg = 1)) *stack_x *= -1;
      convert = *stack_x;
      *stack_x -= convert;
      if (isneg) convert *= -1;
      current->x += convert;
    }
  isneg = 0;
  if (*stack_y > 1 || *stack_y < -1)
    {
      if (*stack_y < 0 && (isneg = 1)) *stack_y *= -1;
      convert = *stack_y;
      *stack_y -= convert;
      if (isneg) convert *= -1;
      current->y += convert;
    }
}

void		perso_coef_directeur_next_pos(t_bunny_position *current,
					      t_bunny_position *target,
					      int vitesse)
{
  static float	stack_x = 0;
  static float	stack_y = 0;
  t_posF	vect;
  t_posF	vect_base;
  float		longueur;

  vect.x = ((float)target->x) - ((float)current->x);
  vect.y = ((float)target->y) - ((float)current->y);
  vect_base.x = ((float)target->x) - ((float)current->x);
  vect_base.y = ((float)target->y) - ((float)current->y);
  longueur = pow(vect.x, 2.0) + pow(vect.y, 2.0);
  longueur = pow(longueur, 0.5);
  vect_base.x = (vect_base.x / longueur) * vitesse;
  vect_base.y = (vect_base.y / longueur) * vitesse;
  stack_x += vect_base.x;
  stack_y += vect_base.y;
  perso_maj_pos(current, &stack_x, &stack_y);
}

void	change_orientation(t_player *player)
{
  int	intervalle_x;
  int	copy_x;
  int	intervalle_y;
  int	copy_y;

  intervalle_x = player->pos.x - player->target.x;
  intervalle_y = player->pos.y - player->target.y;
  copy_y = (intervalle_y < 0) ? intervalle_y * -1: intervalle_y;
  copy_x = (intervalle_x < 0) ? intervalle_x * -1: intervalle_x;
  if (copy_x > copy_y)
    player->orientation = (intervalle_x > 0) ? GAUCHE : DROITE ;
  else
    player->orientation = (intervalle_y > 0) ? HAUT : BAS ;
}

void		moove_perso(t_player *player, t_zone *zone, int vitesse)
{
  static int	i = 0;

  perso_define_next_target(player, zone);
  change_current_node(player, zone);
  if (player->target.x == player->pos.x && player->target.y == player->pos.y)
      return ;
  perso_coef_directeur_next_pos(&player->pos, &player->target, vitesse);
  change_orientation(player);
  i = anim_player(player, i);
  i++;
}
