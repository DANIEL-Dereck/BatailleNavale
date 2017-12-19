/*
** my_putstr.c for my_putstr.c in /home/daniel_d/rendu/Piscine-C-Jour_04
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Thu Oct  3 18:07:56 2013 daniel_d
** Last update Thu Jun 19 13:42:23 2014 daniel_d
*/

#include <stdlib.h>
#include "../my.h"

int	my_putstr(char *str)
{
  int a;

  a = 0;
  if (str != NULL)
    {
      while (str[a] != '\0')
	{
	  my_putchar(str[a]);
	  a = a + 1;
	}
      return (0);
    }
  return (-1);
}
