/*
** my_string.h for myStr in /home/debrau_c/Documents/Prog_Syst_Unix/PSU_2015_minishell1/src
** 
** Made by debrau_c
** Login   <debrau_c@epitech.net>
** 
** Started on  Tue Jan 19 15:19:30 2016 debrau_c
** Last update Thu Apr 14 18:00:55 2016 debrau_c
*/

#ifndef MY_STRING_H
# define MY_STRING_H

int	my_special_strlen(char *str, char stop_fig);
void	my_strncpy(char *src, char *dest, int size);
void	my_strncat(char *src, char *dest, int size);
int	my_putstr(char *str);
int	my_strlen(char *str);
void	my_strcpy(char *src, char *dest);
void	epur_str(char *str);
int	my_strlen(char *str);
char	*my_strdup(char *str);
int	my_strcmp(char *s1, char *s2);
int	my_special_strcmp(char *s1, char *s2);
int	my_putstre(char *str);
char	*my_strdup2(char *s1, char *s2);

#endif /* MY_STRING_H */
