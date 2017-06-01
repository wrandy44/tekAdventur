/*
** init.c for azd in /home/debrau_c/Documents/Igraph/gfx_tekadventure/srcs
** 
** Made by debrau_c
** Login   <debrau_c@epitech.net>
** 
** Started on  Thu Mar 24 16:46:25 2016 debrau_c
** Last update Sun Apr 17 22:57:11 2016 debrau_c
*/

#include "my_inc.h"
#include "load_bmp.h"
#include "my_string.h"

t_interface	*init_interface(void)
{
  t_interface	*interface;

  if ((interface = bunny_malloc(sizeof(t_interface))) == NULL)
    return (NULL);
  if ((interface->img_action_bar =
       bunny_load_pixelarray("pic/action_bar.bmp")) == NULL)
    return (NULL);
  if ((interface->img_sac = bunny_load_pixelarray("pic/sac.bmp")) == NULL)
    return (NULL);
  if ((interface->img_fleche = bunny_load_pixelarray("pic/flech.bmp")) == NULL)
    return (NULL);
  interface->fleche_pos.x = (SCREEN_W / 2) -
    (interface->img_fleche->clipable.clip_width / 2);
  interface->fleche_pos.y = SCREEN_H -
    interface->img_fleche->clipable.clip_height;
  interface->bar_pos.x = 0;
  interface->bar_pos.y = SCREEN_H - 200;
  interface->menu_on = 0;
  interface->sac_on = 0;
  interface->sac_pos.x = 270;
  interface->sac_pos.y = SCREEN_H - 250;
  return (interface);
}

t_bunny_pixelarray	*init_current_zone_calc(t_zone *one_zone)
{
  int			i;
  char			*name;
  t_bunny_pixelarray	*pix;

  if (one_zone->calc_index == -1)
    return (NULL);
  if ((name = my_strdup("pic/calc01.bmp")) == NULL)
    return (NULL);
  i = 0;
  while (i < one_zone->calc_index && i < NB_CALC)
    {
      name[9]++;
      if (name[9] > '9')
	{
	  name[9] = '0';
	  name[8]++;
	}
      i++;
    }
  if ((pix = load_bmp(name)) == NULL)
    return (NULL);
  bunny_free(name);
  return (pix);
}

t_bunny_pixelarray	*init_current_zone_fond(int zone)
{
  int			i;
  char			*name;
  t_bunny_pixelarray	*pix;

  if ((name = my_strdup("pic/fond01.bmp")) == NULL)
    return (NULL);
  i = 0;
  while (i < zone)
    {
      name[9]++;
      if (name[9] > '9')
	{
	  name[9] = '0';
	  name[8]++;
	}
      i++;
    }
  if ((pix = load_bmp(name)) == NULL)
    return (NULL);
  bunny_free(name);
  return (pix);
}

int		init_lapin(t_main_struct *main_s, int zone)
{
  if ((main_s->interface = init_interface()) == NULL)
    return (1);
  if ((main_s->font = load_bmp("pic/font.bmp")) == NULL)
    return (1);
  if ((main_s->zone = init_all_zone(main_s->file_ini, main_s)) == NULL)
    return (1);
  if (init_player(&main_s->player, &main_s->zone[zone]))
    return (1);
  if ((main_s->screen = bunny_start(SCREEN_W, SCREEN_H, NULL,
				    "tekadventure")) == NULL)
    return (1);
  if ((main_s->fond = bunny_new_pixelarray(SCREEN_W, SCREEN_H)) == NULL)
    return (1);
  if ((main_s->current_zone_fond = init_current_zone_fond(zone)) == NULL)
    return (1);
  main_s->current_zone_calc = init_current_zone_calc(&main_s->zone[zone]);
  if ((main_s->bank = init_bank()) == NULL)
    return (1);
  change_zone(main_s);
  return (0);
}
