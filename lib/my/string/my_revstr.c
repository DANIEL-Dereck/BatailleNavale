/*
** my_revstr.c for my_revstr.c in /home/daniel_d/rendu/Piscine-C-Jour_06/ex_03
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Mon Oct  7 13:41:32 2013 daniel_d
** Last update Thu Jun 19 13:41:16 2014 daniel_d
*/

#include <stdlib.h>
#include "../my.h"

int	my_revstr(char *str)
{
  int	i;

  i = 0;
  if (str != NULL)
    {
      while (str[i++] != '\0');
      i--;
      while (i != 0)
	my_putchar(str[i--]);
      return (0);
    }
  return (-1);
}
