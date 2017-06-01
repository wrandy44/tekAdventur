/*
** my_getnbr.c for getnbr in /home/debrau_c/Documents/C_Prog_Elem/CPE_2015_Allum1
** 
** Made by debrau_c
** Login   <debrau_c@epitech.net>
** 
** Started on  Tue Feb  9 16:39:09 2016 debrau_c
** Last update Sun Apr 17 18:26:11 2016 debrau_c
*/

int	my_scan_string(const char *s)
{
  int	i;

  i = 0;
  if (s[0] == '\0') return (1);
  while (s[i] != '\0')
    {
      if (s[i] < '0' || s[i] > '9')
	return (1);
      i++;
    }
  return (0);
}

int	my_get_nbr(const char *s)
{
  int	i;
  int	res;
  int	isneg;

  isneg = 0;
  i = 0;
  if (s[i] == '-')
    {
      i++;
      isneg = 1;
    }
  res = 0;
  if (my_scan_string(&s[i]))
    return (-1);
  while (s[i])
    {
      res = (res * 10) + (s[i] - '0');
      i++;
    }
  if (isneg)
    return (res * -1);
  return (res);
}
