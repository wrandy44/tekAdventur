/*
** edit_gest_menu.c for azd in /home/debrau_c/Documents/Igraph/gfx_tekadventure
** 
** Made by debrau_c
** Login   <debrau_c@epitech.net>
** 
** Started on  Sat Apr 16 12:55:13 2016 debrau_c
** Last update Sun Apr 17 15:22:28 2016 debrau_c
*/

#include <lapin.h>
#include "editeur.h"

int	edit_gest_menu_ext(t_edit *edit,
			   t_bunny_position *mouse)
{
  int	x;
  int	y;

  x = mouse->x;
  y = mouse->y;
  if (x > 872 && x < 957 && y > 707 && y < 727)
    {
      edit_save_ini(edit);
      return (0);
    }
  if (x > 873 && x < 983 && y > 655 && y < 677)
    edit_save_zone(edit);
  return (0);
}

int	edit_gest_menu_mouse_state(t_edit *edit,
				   t_bunny_position *mouse)
{
  int	x;
  int	y;

  x = mouse->x;
  y = mouse->y;
  if (x > 19 && x < 145 && y > 591 && y < 615)
    edit->control.mouse_state = DEFINE_NODE;
  else if (x > 19 && x < 145 && y > 638 && y < 656)
    edit->control.mouse_state = RELIE_NODE;
  else if (x > 18 && x < 145 && y > 678 && y < 698)
    edit->control.mouse_state = DEFINE_START;
  else if (x > 19 && x < 145 && y > 723 && y < 747)
    edit->control.mouse_state = DEFINE_END;
  return (0);
}

int	edit_gest_menu(t_edit *edit,
		       t_bunny_position *mouse)
{
  int	x;
  int	y;

  x = mouse->x;
  y = mouse->y;
  if (x > 339 && x < 371 && y > 617 && y < 648)
    edit->zone.index_fond++;
  else if (x > 216 && x < 247 && y > 616 && y < 651)
    edit->zone.index_fond--;
  else if (x > 340 && x < 375 && y > 685 && y < 728)
    edit->zone.index_calc++;
  else if (x > 224 && x < 263 && y > 685 && y < 728)
    edit->zone.index_calc--;
  else if (x > 548 && x < 584 && y > 624 && y < 660)
    edit->zone.next_zone++;
  else if (x > 423 && x < 454 && y > 621 && y < 660)
    edit->zone.next_zone--;

  edit_gest_menu_mouse_state(edit, mouse);
  if ((edit_gest_menu_ext(edit, mouse)) == 2)
    return (2);
  return (0);
}
