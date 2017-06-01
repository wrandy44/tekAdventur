/*
** main.c for main in /home/debrau_c/bin/new_repo/srcs
** 
** Made by debrau_c
** Login   <debrau_c@epitech.net>
** 
** Started on  Tue Jan 19 16:55:58 2016 debrau_c
** Last update Thu May  4 22:29:02 2017 debrau_c
*/

#include "my_inc.h"
#include "load_bmp.h"
#include "init.h"
#include "node.h"

t_bunny_response	my_loop(void *data)
{
  t_main_struct		*tmp;
  t_bunny_position	*mouse;

  tmp = (t_main_struct *)data;
  if ((mouse = (t_bunny_position *)bunny_get_mouse_position()) == NULL)
    return (EXIT_ON_ERROR);
  interface_check_fleche(tmp->interface, mouse);
  moove_perso(&tmp->player, &tmp->zone[tmp->current_zone - 1], 5);
  if (change_zone(tmp)) return (EXIT_ON_ERROR);
  all_drawing(tmp);
  return (GO_ON);
}

t_bunny_response	my_keyset(t_bunny_event_state state,
				  t_bunny_keysym keysym,
				  void *data)
{
  data = data;
  if (keysym == BKS_ESCAPE)
    if (state == GO_DOWN)
      return (GO_ON);
  return (GO_ON);
}

int			define_custom_map(char *name_file, t_main_struct *mainS)
{
  if ((mainS->file_ini = my_strdup(name_file)) == NULL)
    return (1);
  return (0);
}

int			get_max_ram()
{
  t_bunny_ini		*config;
  char			*v;
  int			res;

  
    if ((config = bunny_load_ini("configuration.ini")) == NULL)
  return (-1);
    //if ((v = (char *)bunny_ini_get_field(config, NULL, "max_ram", 0)) == NULL)
    //return (-1);
  res = my_get_nbr("12");
  bunny_delete_ini(config);
  return (150000000);
}

int			main(int argc, char **argv)
{
  t_main_struct		main_s;
  int			ram;

  main_s.debug_mode = 0;
  if ((ram = get_max_ram()) == -1)
    return (1);
  //bunny_set_maximum_ram(ram);
  main_s.current_zone = 1;
  if ((catch_debug_mode(argc, argv, &main_s)) == 2)
    return (editeur());
  if (init_lapin(&main_s, main_s.current_zone - 1))
    return (1);
  bunny_set_click_response(&my_mouse_set);
  bunny_set_key_response(&my_keyset);
  bunny_set_loop_main_function(&my_loop);
  bunny_loop(main_s.screen, 60, &main_s);
  return (0);
}
