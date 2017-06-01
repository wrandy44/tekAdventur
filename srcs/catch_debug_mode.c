/*
** catch_debug_mode.c for azd in /home/debrau_c/Documents/Igraph/gfx_tekadventure
** 
** Made by debrau_c
** Login   <debrau_c@epitech.net>
** 
** Started on  Sun Apr 17 18:13:15 2016 debrau_c
** Last update Sun Apr 17 18:14:50 2016 debrau_c
*/

#include "my_inc.h"
#include "load_bmp.h"
#include "init.h"
#include "node.h"

int			catch_debug_mode(int argc,
					 char **argv,
					 t_main_struct *mainS)
{
  int	i;

  mainS->file_ini = NULL;
  if (argc > 1)
    {
      i = 1;
      while (i < argc)
	{
	  if (argv[i][0] == '-' && argv[i][1] == 'd')
	    mainS->debug_mode = 1;
	  if (argv[i][0] == '-' && argv[i][1] == 'e')
	    return (2);
	  if (argv[i][0] == '-' && argv[i][1] == 'c' && argv[i][2] == '=')
	    if (define_custom_map(&argv[i][3], mainS))
	      return (1);
	  i++;
	}
    }
  if (mainS->file_ini == NULL)
    if (define_custom_map("zone/histoire.ini", mainS))
      return (1);
  return (0);
}
