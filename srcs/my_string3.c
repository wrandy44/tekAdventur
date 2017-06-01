/*
** my_string3.c for my_string3 in /home/debrau_c/Documents/Prog_Syst_Unix/PSU_2015_minishell1/src
** 
** Made by debrau_c
** Login   <debrau_c@epitech.net>
** 
** Started on  Thu Jan 21 19:21:23 2016 debrau_c
** Last update Sun Apr 17 18:34:32 2016 debrau_c
*/

#include <unistd.h>
#include <lapin.h>
#include "my_string.h"

char	*my_strdup2(char *s1, char *s2)
{
  int	size;
  int	i;
  int	j;
  char	*new;

  size = my_strlen(s1) + my_strlen(s2) + 3;
  if ((new = bunny_malloc(sizeof(char) * size)) == NULL)
    return (NULL);
  i = -1;
  while (s1[++i])
    new[i] = s1[i];
  j = -1;
  while (s2[++j])
    {
      new[i] = s2[j];
      i++;
    }
  return (new);
}

int	my_special_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  while (s1[i] != '\0' && s1[i] == s2[i])
    i++;
  if (s2[i] == '\0')
    return (0);
  return (1);
}

int	my_putstre(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      write(2, &str[i], 1);
      i++;
    }
  return (1);
}
