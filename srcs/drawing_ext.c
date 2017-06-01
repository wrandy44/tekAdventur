/*
** drawing_ext.c for azd in /home/debrau_c/Documents/Igraph/gfx_tekadventure
** 
** Made by debrau_c
** Login   <debrau_c@epitech.net>
** 
** Started on  Sun Apr 17 17:26:28 2016 debrau_c
** Last update Sun Apr 17 17:30:36 2016 debrau_c
*/

#include "my_inc.h"

float			draw_define_zoom(const t_zoom *zoom,
					 const t_player *player)
{
  float			res;
  int			real_y;
  int			echelle;
  float			lv_echelle;

  real_y = player->pos.y;
  if (zoom->end < zoom->start)
    {
      if (real_y < zoom->end) return (zoom->lv_end);
      else if (real_y > zoom->start) return (zoom->lv_start);
      else
	{
	  echelle = zoom->start - zoom->end;
	  lv_echelle = zoom->lv_end - zoom->lv_start;
	  return ((real_y * lv_echelle) / echelle);
	}
    }
  if (real_y > zoom->end) return (zoom->lv_end);
  else if (real_y < zoom->start) return (zoom->lv_start);
  echelle = zoom->end - zoom->start;
  lv_echelle = zoom->lv_start - zoom->lv_end;
  return ((((float)real_y) * lv_echelle) / ((float)echelle));
  return (res);
}

void			draw_player(t_player *player,
				    t_zone *one_zone,
				    t_bunny_pixelarray *fond)
{
  t_bunny_pixelarray	*copy_player;
  t_bunny_pixelarray	*copy_player_zoomed;
  float			zoom;

  zoom = zone_get_zoom(one_zone, player->pos);
  if ((copy_player = draw_copy_player(player->img, player->rect)) == NULL)
    return ;
  if ((copy_player_zoomed = tekzoom(copy_player, zoom)) == NULL)
    return ;
  bunny_delete_clipable(&copy_player->clipable);
  player->pos.y -= copy_player_zoomed->clipable.clip_height;
  my_alpha_blit(fond, copy_player_zoomed, &player->pos, NULL);
  player->pos.y += copy_player_zoomed->clipable.clip_height;
  bunny_delete_clipable(&copy_player_zoomed->clipable);
}

void			draw_calc_debug(t_main_struct *mainS,
					t_bunny_pixelarray *fond,
					int curr_z)
{
  if (mainS->debug_mode)
    node_drawing_node_with_tol(&mainS->zone[curr_z], fond);
}

void			draw_calc_zone(t_bunny_pixelarray *fond,
				       t_bunny_pixelarray *calc,
				       t_zone *one_zone,
				       t_bunny_rect *camera)
{
  if (one_zone->calc_index != -1)
    my_alpha_blit(fond, calc, NULL, camera);
}

void			all_drawing(t_main_struct *mainS)
{
  t_bunny_pixelarray	*fond;
  t_bunny_rect		camera;
  int			curr_z;

  camera.x = 0;
  camera.y = 0;
  camera.h = SCREEN_H;
  camera.w = SCREEN_W;
  curr_z = mainS->current_zone -1;
  fond = mainS->fond;
  my_bunny_fill(fond, WHITE);
  my_alpha_blit(fond, mainS->current_zone_fond, NULL, &camera);
  draw_player(&mainS->player, &mainS->zone[curr_z], fond);
  draw_object_zone(&mainS->zone[curr_z], mainS->bank->obj, fond);
  draw_calc_zone(fond, mainS->current_zone_calc,
		 &mainS->zone[curr_z], &camera);
  draw_calc_debug(mainS, fond, curr_z);
  draw_interface(mainS->interface, mainS);
  bunny_blit(&mainS->screen->buffer, &fond->clipable, NULL);
  bunny_display(mainS->screen);
}
