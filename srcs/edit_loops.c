/*
** edit_loops.c for zad in /home/debrau_c/Documents/Igraph/gfx_tekadventure
** 
** Made by debrau_c
** Login   <debrau_c@epitech.net>
** 
** Started on  Fri Apr 15 14:59:28 2016 debrau_c
** Last update Sun Apr 17 16:14:21 2016 debrau_c
*/

#include <lapin.h>
#include "editeur.h"
#include "mylapin.h"

void			edit_check_mouse(t_bunny_position *mouse,
					 t_edit *data)
{
  if ((mouse->x > 468 && mouse->x < 563)
      && (mouse->y > 728 && mouse->y < 765))
    data->control.on_fleche = 1;
  if (data->control.on_fleche == 1
      && mouse->y < E_SCREEN_H - 200)
    data->control.on_fleche = 0;
}

t_bunny_response	edit_loop(void *data)
{
  t_edit		*data_e;
  t_bunny_position	*mouse_pos;

  if ((mouse_pos = (t_bunny_position *)bunny_get_mouse_position()) == NULL)
    return (EXIT_ON_ERROR);
  data_e = (t_edit *) data;
  bunny_blit(&data_e->screen->buffer, &data_e->fond->clipable, NULL);
  edit_draw(data_e);
  edit_check_mouse(mouse_pos, data_e);
  bunny_display(data_e->screen);
  return (GO_ON);
}

t_bunny_response	edit_keyset(t_bunny_event_state state,
				    t_bunny_keysym keysym,
				    void *data)
{
  t_edit		*edit;

  edit = data;
  if (state == GO_DOWN)
    {
      if (keysym == BKS_ESCAPE)
	edit->control.menu_save = (edit->control.menu_save == 0) ? 1 : 0;
      if (edit->control.menu_save == 1)
	{
	  edit_gest_save_file(edit, keysym);
	  if (keysym == 58)
	    {
	      edit_save_ini(edit);
	      return (EXIT_ON_SUCCESS);
	    }
	}
    }
  return (GO_ON);
}
