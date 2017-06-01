/*
** my_itoa.c for ad in /home/debrau_c/Documents/Igraph/gfx_tekadventure
** 
** Made by debrau_c
** Login   <debrau_c@epitech.net>
** 
** Started on  Sat Apr 16 01:19:55 2016 debrau_c
** Last update Sun Apr 17 18:34:50 2016 debrau_c
*/

#include <lapin.h>

int	count_size_str(int nb)
{
  int	i;

  i = 0;
  if (nb == 0)
    return (2);
  if (nb < 0)
    {
      nb *= -1;
      i++;
    }
  while (nb > 0)
    {
      nb = nb / 10;
      i++;
    }
  return (i + 1);
}

void	my_rev(char *str)
{
  int	size;
  int	i;
  char	tmp;

  i = -1;
  size = 0;
  if (str[i + 1] == '-') i++;
  while (str[size]) size++;
  while (++i < --size)
    {
      tmp = str[i];
      str[i] = str[size];
      str[size] = tmp;
    }
}

char	*my_itoa(int nb)
{
  char	*str;
  int	i;

  if ((str = bunny_malloc(sizeof(char) * count_size_str(nb))) == NULL)
    return (NULL);
  if (nb == 0 && (str[0] = '0') && (str[1] = '\0') + 1)
    return (str);
  i = 0;
  if (nb < 0 && (nb *= -1)) str[i++] = '-';
  while (nb > 0)
    {
      str[i] = (nb % 10) + '0';
      nb /= 10;
      i++;
    }
  str[i] = '\0';
  my_rev(str);
  return (str);
}
