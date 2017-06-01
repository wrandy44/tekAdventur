/*
** my_ini_ress.c for azd in /home/debrau_c/Documents/Igraph/gfx_tekadventure
** 
** Made by debrau_c
** Login   <debrau_c@epitech.net>
** 
** Started on  Wed Mar 30 03:15:58 2016 debrau_c
** Last update Sun Apr 17 16:40:17 2016 debrau_c
*/

#include <lapin.h>

char	*my_ini_get(const t_bunny_ini *ini,
		    const char *sc,
		    const char *fi,
		    const int i)
{
  char	*s;

  s = (char *)bunny_ini_get_field(ini, sc, fi, i);
  return (s);
}

int	my_ini_count_member(const t_bunny_ini *ini,
			    const char *sc,
			    const char *fi)
{
  char	*s;
  int	i;

  i = 0;
  while (1)
    {
      s = (char *)bunny_ini_get_field(ini, sc, fi, i);
      if (s == NULL)
	return (i);
      i++;
    }
  return (0);
}
