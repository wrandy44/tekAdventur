/*
** my_string.c for myString in /home/debrau_c/Documents/Prog_Syst_Unix/PSU_2015_minishell1/src
** 
** Made by debrau_c
** Login   <debrau_c@epitech.net>
** 
** Started on  Tue Jan 19 15:19:02 2016 debrau_c
** Last update Sun Apr 17 23:22:42 2016 debrau_c
*/

#include <unistd.h>

void	my_strncpy(char *src, char *dest, int size)
{

  int	i;

  i = 0;
  while (src[i] != '\0' && i <= size)
    {
      dest[i] = src[i];
      i++;
    }
  dest[i] = '\0';
}

void	my_strncat(char *src, char *dest, int size)
{
  int	i;
  int	k;

  i = 0;
  k = 0;
  while (dest[i] != '\0') i++;
  while (size >= 0)
    {
      dest[i] = src[k];
      size--;
      i++;
      k++;
    }
  dest[i] = '\0';
}

int	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      write(1, &str[i], 1);
      i++;
    }
  return (i);
}

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    i++;
  return (i);
}

void	my_strcpy(char *src, char *dest)
{
  int	i;

  i = 0;
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i++;
    }
  dest[i] = '\0';
}
