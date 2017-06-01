/*
** my_get_float.c for aazd in /home/debrau_c/Documents/Igraph/gfx_tekadventure/srcs
** 
** Made by debrau_c
** Login   <debrau_c@epitech.net>
** 
** Started on  Wed Mar 30 13:37:59 2016 debrau_c
** Last update Sun Apr 17 16:47:09 2016 debrau_c
*/

int	my_get_float_ext(const char *str,
			 int *isneg,
			 float *res,
			 int *i)
{
  *res = 0;
  if (str[0] == '-')
    {
      *isneg = 1;
      *i = *i + 1;
    }
  while (str[*i] != '.' && str[*i] != '\0')
    {
      *res = (str[*i] - '0') + (*res * 10);
      *i = *i + 1;
    }
  if (str[*i] == '\0')
    {
      if (*isneg)
	*res = *res * -1;
      return (1);
    }
  return (0);
}

float	my_get_float(const char *str)
{
  int	i;
  float	res;
  int	isneg;
  float	div;

  i = 0;
  isneg = 0;
  if (my_get_float_ext(str, &isneg, &res, &i))
    return (res);
  div = 0.1;
  while (str[i] != '\0')
    {
      res = ((str[i] - '0') * div) + res;
      div /= 10;
      i++;
    }
  if (isneg) return (res * -1);
  return (res);
}
