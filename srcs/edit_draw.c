/*
** edit_draw.c for zad in /home/debrau_c/Documents/Igraph/gfx_tekadventure
** 
** Made by debrau_c
** Login   <debrau_c@epitech.net>
** 
** Started on  Fri Apr 15 15:20:57 2016 debrau_c
** Last update Sun Apr 17 18:37:24 2016 debrau_c
*/

#include <lapin.h>
#include "mylapin.h"
#include "editeur.h"
#include "load_bmp.h"
#include "my_string.h"

void			edit_draw_interface_init(t_bunny_position *pos_fleche,
						 t_bunny_position *pos_menu,
						 t_edit_img *imgs)
{
  pos_fleche->x = (E_SCREEN_W / 2) - (imgs->fleche->clipable.clip_width / 2);
  pos_fleche->y = E_SCREEN_H - imgs->fleche->clipable.clip_height;
  pos_menu->x = 0;
  pos_menu->y = E_SCREEN_H - 200;
}

void			edit_draw_interface(t_edit *data)
{
  t_bunny_position	pos_fleche;
  t_bunny_position	pos_menu;
  t_edit_img		*imgs;
  char			*value;

  imgs = &data->imgs;
  edit_draw_interface_init(&pos_fleche, &pos_menu, imgs);
  bunny_blit(&data->screen->buffer, &imgs->fleche->clipable, &pos_fleche);
  if (data->control.on_fleche == 1)
    {
      bunny_blit(&data->screen->buffer, &imgs->menu->clipable, &pos_menu);
      pos_menu.x += 455;
      pos_menu.y += 55;
      if ((value = my_itoa(data->zone.next_zone)) == NULL) return ;
      my_bunny_fill(imgs->next_scene, WHITE);
      tektext(imgs->next_scene, &data->imgs.font, NULL, value);
      bunny_free(value);
      bunny_blit(&data->screen->buffer, &imgs->next_scene->clipable,
		 &pos_menu);
    }
  if (data->zone.index_fond == -1) my_bunny_fill(data->fond, WHITE);
  else edit_draw_fond(data->fond, data->zone.index_fond);
  if (data->zone.index_calc != -1)
    edit_draw_calc(data->fond, data->zone.index_calc);
}

void	edit_draw_menu_save(t_edit *data)
{
  t_bunny_position	pos;
  t_bunny_position	entry;

  pos.x = E_SCREEN_W / 2 - 200;
  pos.y = E_SCREEN_H / 2 - 200;
  entry.x = 10;
  entry.y = 10;
  my_bunny_fill(data->imgs.menu_save, WHITE);
  tektext(data->imgs.menu_save, &data->imgs.font, &entry,
	  "Choose name file :");
  entry.y = 80;
  tektext(data->imgs.menu_save, &data->imgs.font, &entry, data->chemin_file);
  bunny_blit(&data->screen->buffer,
	     &data->imgs.menu_save->clipable,
	     &pos);
}

void	edit_draw(t_edit *data)
{
  edit_draw_interface(data);
  edit_draw_node(data->zone.nodes, data->control.index_first_node, data->fond);
  edit_draw_chemin(data->fond, data->zone.nodes, data->zone.chemin);
  if (data->control.menu_save)
    edit_draw_menu_save(data);
}
