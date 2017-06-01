/*
** my_inc.h for  in /home/debrau_c/bin/new_repo_info
** 
** Made by debrau_c
** Login   <debrau_c@epitech.net>
** 
** Started on  Fri Feb 19 11:20:27 2016 debrau_c
** Last update Sun Apr 17 23:30:35 2016 debrau_c
*/

#ifndef MY_H
# define MY_H

# include <lapin.h>
# include "mylapin.h"
# include "my_string.h"
# define SCREEN_W 1024
# define SCREEN_H 768
# define NB_OBJECTS 1
# define NB_CALC 1

typedef struct		s_posF
{
  float			x;
  float			y;
  float			h;
  float			w;
}			t_posF;

typedef struct		s_bankImg
{
  t_bunny_pixelarray	*obj[NB_OBJECTS];
}			t_bankImg;

typedef struct		s_zoom
{
  int			active;
  int			end;
  int			start;
  float			lv_end;
  float			lv_start;
}			t_zoom;

typedef struct		s_sac
{
  int			vide;
  char			*name;
  int			index_img;
}			t_sac;

typedef struct		s_object
{
  int			exist;
  char			*name;
  int			event_node;
  char			*event_type;
  t_bunny_position	pos;
  int			pix_index;
  int			block;
}			t_object;

typedef struct		s_interface
{
  int			menu_on;
  int			sac_on;
  t_bunny_pixelarray	*img_action_bar;
  t_bunny_pixelarray	*img_fleche;
  t_bunny_pixelarray	*img_sac;
  t_bunny_position	fleche_pos;
  t_bunny_position	bar_pos;
  t_bunny_position	sac_pos;
}			t_interface;

typedef struct		s_zone
{
  int			start;
  int			nb_end;
  int			*end;
  int			*end_defined_node;
  int			*next;
  t_zoom		zoom;
  int			calc_index;
  int			fond_index;
  int			nb_obj;
  t_object		*obj;
  int			tolerance;
  int			nb_noeud;
  t_bunny_position	*pos_noeud;
  char			*chemin;
}			t_zone;

typedef struct		s_player
{
  int			orientation;
  t_bunny_pixelarray	*img;
  t_bunny_position	pos;
  int			current_node;
  int			path_node;
  int			target_node;
  t_bunny_position	target;
  t_bunny_rect		rect;
  t_sac			sac[5];
  int			isSpawn;
}			t_player;

typedef struct		s_main_struct
{
  char			*file_ini;
  int			nb_zone;
  int			debug_mode;
  int			current_zone;
  t_bunny_window	*screen;
  t_bunny_pixelarray	*fond;
  t_bunny_pixelarray	*current_zone_fond;
  t_bunny_pixelarray	*current_zone_calc;
  t_bunny_pixelarray	*font;
  t_zone		*zone;
  t_player		player;
  t_interface		*interface;
  t_bankImg		*bank;
}			t_main_struct;

int			my_get_nbr(const char *s);
int			load_zone(t_zone *zone, const char *name_file,
				  const char *name_zone);
int			load_zone_catch_all_end_next(t_zone *zone, t_bunny_ini *ini,
						     const char *name);
int			load_zone_node_and_tol(t_zone *zone,
					       const char *name_zone,
					       t_bunny_ini *ini);
int			load_zone_next_and_start(t_zone *zone,
						 t_bunny_ini *ini,
						 const char *name_zone);
t_object		*load_zone_object(t_zone *one_zone,
					  t_bunny_ini *ini,
					  const char *name_zone);
int			draw_zone(t_zone *zone, t_bunny_pixelarray *pix);
void			special_filling(t_bunny_pixelarray *pix,
					t_bunny_position *posFirst,
					unsigned int new_color);
int			interface_check_fleche(t_interface *inter,
					       t_bunny_position *mouse);
void			moove_perso(t_player *player, t_zone *zone, int vitesse);
int			change_zone(t_main_struct *mainS);
int			node_check_click_to_node(const t_bunny_position  *mouse_pos,
						 t_zone *zone);
void			all_drawing(t_main_struct *mainS);
void			node_drawing_node_with_tol(t_zone *zone,
						   t_bunny_pixelarray *fond);
int			action_ramasser(t_player *player,
					t_zone *zone,
					t_main_struct *mainS);
t_bunny_response	my_mouse_set(t_bunny_event_state state,
				     t_bunny_mousebutton button,
				     void *data);
t_bunny_pixelarray	*tekzoom(t_bunny_pixelarray *p,
				 float zoom);
float			my_get_float(const char *str);
int			msg_anim_rammassage(t_bunny_window *win,
					    t_bunny_pixelarray *font,
					    char *object);
float			zone_get_zoom(t_zone *one_zone, t_bunny_position pos);
t_bunny_pixelarray	*draw_copy_player(t_bunny_pixelarray *img_p,
					  t_bunny_rect rect_p);
int			load_zone_node_and_tol(t_zone *zone,
					       const char *name_zone,
					       t_bunny_ini *ini);
int			load_zone_next_and_start(t_zone *zone,
						 t_bunny_ini *ini,
						 const char *name_zone);
t_object		*load_zone_object(t_zone *one_zone,
					  t_bunny_ini *ini,
					  const char *name_zone);
int			load_zone_zoom(t_zoom *zoom_z,
				       t_bunny_ini *ini,
				       const char *name_zone);
char			*zone_define_chemin(const t_bunny_ini *new,
					    const char *name_zone);
int			zone_recup_noeud(t_bunny_ini *new,
					 t_zone *one_zone,
					 const char *name_zone);
int			load_zone_img(t_zone *one_zone,
				      const t_bunny_ini *ini,
				      const char *name_zone);
void			my_blit_fond(t_bunny_pixelarray *win,
				     t_bunny_pixelarray *pix,
				     t_bunny_position *pos);
int			action_ouvrir(t_player *player,
				      t_zone *zone,
				      t_main_struct *mainS);
int			message_anim(t_bunny_window *win,
				     t_bunny_pixelarray *font,
				     char *message);
int			editeur(void);
void			perso_coef_directeur_init_coef_b(t_bunny_position pos1,
							 t_bunny_position pos2,
							 float *coef,
							 float *b);
void			perso_maj_pos(t_bunny_position *current,
				      float *stack_x,
				      float *stack_y);
void			perso_coef_directeur_next_pos(t_bunny_position *current,
						      t_bunny_position *target,
						      int vitesse);
void			change_orientation(t_player *player);
void			moove_perso(t_player *player, t_zone *zone, int vitesse);
void			change_current_node(t_player *player, t_zone *zone);
int			anim_player(t_player *player, int i);
int			perso_define_next_node(t_player *player,
					       t_zone *zone);
void			perso_define_next_target(t_player *player,
						 t_zone *zone);
void			perso_coef_directeur_init(t_bunny_position *current,
						  t_bunny_position *next,
						  t_bunny_rect rect);
int			message_anim_ext(t_bunny_pixelarray *pix,
					 t_font *font,
					 char *message,
					 int nb_frame);
void			draw_interface(t_interface *interface, t_main_struct *mainS);
void			draw_object_zone(t_zone *one_zone,
					 t_bunny_pixelarray **imgs_obj,
					 t_bunny_pixelarray *fond);
t_zone			*init_all_zone(const char *name_file, t_main_struct *mainS);
int			init_player(t_player *player, t_zone *zone);
t_bankImg		*init_bank(void);
int			catch_debug_mode(int argc,
					 char **argv,
					 t_main_struct *mainS);
int			define_custom_map(char *name_file, t_main_struct *mainS);
void			change_zone_refresh_player_node(t_player *player,
							t_zone *zone,
							int node);
void			change_zone_refresh_player(t_player *player, t_zone *zone);
t_bunny_pixelarray	*change_current_zone_fond(int nb);
t_bunny_pixelarray	*change_current_zone_calc(int nb);
int			change_zone_define_end_next(t_main_struct *mainS,
						    int *end);
enum
  {
    RAMASSER,
    PARLER,
    OUVRIR,
    RIEN
  };

enum
  {
    HAUT,
    BAS,
    GAUCHE,
    DROITE
  };

#endif /* MY_H */
