/*
** my_string2.c for myStr2 in /home/debrau_c/Documents/Prog_Syst_Unix/PSU_2015_minishell1
** 
** Made by debrau_c
** Login   <debrau_c@epitech.net>
** 
** Started on  Tue Jan 19 15:25:06 2016 debrau_c
** Last update Sun Apr 17 18:32:29 2016 debrau_c
*/

#include <lapin.h>
#include "my_string.h"

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  while (s1[i] == s2[i] && s1[i] != '\0')
    i++;
  return (s1[i] - s2[i]);
}

char	*my_strdup(char *str)
{
  char	*new_str;
  int	i;

  i = 0;
  if ((new_str = bunny_malloc(sizeof(char) * (my_strlen(str) + 2))) == NULL)
    return (NULL);
  while (str[i])
    {
      new_str[i] = str[i];
      i++;
    }
  new_str[i] = '\0';
  return (new_str);
}

void	epur_str_ext(char *str)
{
  int	i;

  i = 0;
  if (str[0] == ' ' || str[0] == '\t')
    while (str[i])
      {
	str[i] = str[i + 1];
	i++;
      }
  if (str[my_strlen(str) - 1] == ' ' || str[my_strlen(str) - 1] == '\t')
    str[my_strlen(str) - 1] = '\0';
}

void	epur_str(char *str)
{
  int	i;
  int	j;

  i = 1;
  while (str[i] != '\0')
    {
      if ((str[i - 1] == ' ' && str[i] == ' ')
	  || (str[i] == '\t'))
	{
	  j = i;
	  while (str[j])
	    {
	      str[j] = str[j + 1];
	      j++;
	    }
	  i--;
	}
      i++;
    }
  epur_str_ext(str);
}

int	my_special_strlen(char *str, char stop_fig)
{
  int	i;

  i = 0;
  while (str[i] != stop_fig && str[i] != '\0') i++;
  return (i - 1);
}
