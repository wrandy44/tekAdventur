/*
** my_realloc.c for zad in /home/debrau_c/Documents/Igraph/gfx_tekadventure
** 
** Made by debrau_c
** Login   <debrau_c@epitech.net>
** 
** Started on  Sat Apr 16 17:50:22 2016 debrau_c
** Last update Sun Apr 17 18:35:01 2016 debrau_c
*/

#include <lapin.h>

char	*my_realloc(char *last, int nb)
{
  char	*new;
  int	i;

  if ((new = bunny_malloc(sizeof(char) * (nb + 2))) == NULL)
    return (NULL);
  i = -1;
  while (last[++i])
    new[i] = last[i];
  new[i] = '\0';
  return (new);
}
