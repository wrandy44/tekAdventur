/*
** editeur.h for zad in /home/debrau_c/Documents/Igraph/gfx_tekadventure
** 
** Made by debrau_c
** Login   <debrau_c@epitech.net>
** 
** Started on  Fri Apr 15 14:53:54 2016 debrau_c
** Last update Sun Apr 17 22:53:23 2016 debrau_c
*/

#ifndef EDITEUR_H
# define EDITEUR_H

# include "mylapin.h"
# define E_SCREEN_W 1024
# define E_SCREEN_H 768

typedef struct		s_e_node
{
  int			index;
  int			start;
  int			end;
  t_bunny_position	pos;
  struct s_e_node	*next;
}			t_e_node;

typedef struct		s_edit_zone
{
  char			*name;
  t_e_node		*nodes;
  char			*chemin;
  int			index_fond;
  int			index_calc;
  int			next_zone;
}			t_edit_zone;

typedef struct		s_control
{
  int			on_fleche;
  int			mouse_state;
  int			index_first_node;
  int			index_second_node;
  int			menu_save;
}			t_control;

typedef struct		s_edit_img
{
  t_bunny_pixelarray	*menu;
  t_bunny_pixelarray	*fleche;
  t_bunny_pixelarray	*next_scene;
  t_bunny_pixelarray	*menu_save;
  t_font		font;
}			t_edit_img;

typedef struct		s_edit
{
  char			*chemin_file;
  t_bunny_window	*screen;
  t_bunny_pixelarray	*fond;
  t_bunny_pixelarray	*calc;
  t_edit_img		imgs;
  t_control		control;
  t_edit_zone		zone;
  t_bunny_ini		*ini;
}			t_edit;

int			editeur(void);
int			edit_init(t_edit *data);
t_bunny_response	edit_loop(void *data);
t_bunny_response	edit_mouse(t_bunny_event_state state,
				   t_bunny_mousebutton button,
				   void *data);
t_bunny_response	edit_keyset(t_bunny_event_state state,
				    t_bunny_keysym keysym,
				    void *data);
void			edit_draw(t_edit *data);
int			edit_save_ini(t_edit *data);
t_e_node		*push_node(t_bunny_position *mouse);
char			*my_itoa(int nb);
int			edit_relie_node(t_bunny_position *mouse,
					t_edit_zone *nodes,
					t_control *control);
int			edit_gest_menu(t_edit *edit,
				       t_bunny_position *mouse);
int			edit_save_zone(t_edit *data);
int			edit_define_important_node(t_bunny_position *mouse,
						   t_edit_zone *zone,
						   int mouse_state);
int			edit_gest_save_file(t_edit *data,
					    t_bunny_keysym keysym);
int			edit_save_next_obj_zoom(t_bunny_ini *ini,
						char *name_zone,
						t_edit_zone *zone);
int			edit_save_end_start(t_bunny_ini *ini,
					    char *name_zone,
					    t_edit_zone *zone);
void			edit_draw_chemin(t_bunny_pixelarray *fond,
					 t_e_node *nodes,
					 char *chemin);
void			edit_draw_node(t_e_node *nodes,
				       int index_first_node,
				       t_bunny_pixelarray *fond);
void			edit_draw_calc(t_bunny_pixelarray *fond,
				       int index);
void			edit_draw_fond(t_bunny_pixelarray *fond,
				       int index);
enum
  {
    DEFINE_NODE,
    RELIE_NODE,
    DEFINE_END,
    DEFINE_START
  };

#endif /* EDITEUR_H */
