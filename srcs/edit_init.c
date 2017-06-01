/*
** edit_init.c for azd in /home/debrau_c/Documents/Igraph/gfx_tekadventure
** 
** Made by debrau_c
** Login   <debrau_c@epitech.net>
** 
** Started on  Fri Apr 15 15:30:51 2016 debrau_c
** Last update Sun Apr 17 15:41:53 2016 debrau_c
*/

#include <lapin.h>
#include "mylapin.h"
#include "editeur.h"
#include "load_bmp.h"
#include "my_string.h"

void	edit_init_control(t_control *control)
{
  control->on_fleche = 0;
  control->mouse_state = DEFINE_NODE;
  control->index_first_node = -1;
  control->index_second_node = -1;
  control->menu_save = 0;
}

int	edit_init_zone(t_edit_zone *zone)
{
  zone->nodes = NULL;
  zone->chemin = NULL;
  zone->index_fond = -1;
  zone->index_calc = -1;
  if ((zone->name = my_strdup("zone01")) == NULL)
    return (1);
  zone->next_zone = -1;
  return (0);
}

int	edit_init_font(t_font *font)
{
  if ((font->img = load_bmp("pic/font.bmp")) == NULL)
    return (1);
  font->size = 10;
  return (0);
}

int	edit_init_img(t_edit *data)
{
  if ((data->screen = bunny_start(E_SCREEN_W,
				  E_SCREEN_H, NULL, "editeur")) == NULL)
    return (1);
  if ((data->fond = bunny_new_pixelarray(E_SCREEN_W, E_SCREEN_H)) == NULL)
    return (1);
  if ((data->imgs.menu = load_bmp("pic/edit_menu.bmp")) == NULL)
    return (1);
  if ((data->imgs.fleche = load_bmp("pic/flech.bmp")) == NULL)
    return (1);
  if ((data->imgs.next_scene = bunny_new_pixelarray(80, 30)) == NULL)
    return (1);
  if ((data->imgs.menu_save = bunny_new_pixelarray(300, 300)) == NULL)
    return (1);
  my_bunny_fill(data->fond, WHITE);
  return (0);
}

int	edit_init(t_edit *data)
{
  if ((data->chemin_file = my_strdup("\0")) == NULL)
    return (1);
  if (edit_init_img(data))
    return (1);
  if ((data->ini = bunny_new_ini()) == NULL) return (1);
  edit_init_control(&data->control);
  if (edit_init_font(&data->imgs.font)) return (1);
  return (edit_init_zone(&data->zone));
}
