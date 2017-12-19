/*
** my_nmatch.c for nmatch in /home/daniel_d/rendu
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Tue Apr 22 15:36:12 2014 daniel_d
** Last update Thu Jun 19 13:41:04 2014 daniel_d
*/

#include <stdlib.h>
#include "../my.h"

int	my_nmatch_bis(char *s1, char *s2, int pos)
{
  int	i;

  i = 0;
  if (pos > my_strlen(s2))
    return (-1);
  while (i <= pos)
    {
      if (s1[i] != s2[i])
	return (-1);
      i++;
    }
  return (0);
}

int	my_nmatch(char *s1, char *s2, int pos)
{
  int	len1;
  int	len2;
  int	result;

  result = 0;
  len1 = my_strlen(s1);
  len2 = my_strlen(s2);
  if (pos <= 0 || s1 == NULL || s2 == NULL)
    return (-1);
  if (len1 >= len2)
    result = my_nmatch_bis(s1, s2, pos);
  else
    result = my_nmatch_bis(s2, s1, pos);
  return (result);
}
