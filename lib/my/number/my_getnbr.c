/*
** my_getnbr.c for my_getnbr.c in /home/daniel_d/rendu/Piscine-C-Jour_04
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Wed Oct  9 10:24:06 2013 daniel_d
** Last update Thu Jun 19 13:43:28 2014 daniel_d
*/

#include <stdlib.h>
#include "../my.h"

int     my_getnbr(char *str)
{
  int   i;
  int   nb;
  int   sign;

  i = 0;
  nb = 0;
  sign = 1;
  if (str == NULL)
    return (0);
  while (str[i] && (str[i] == '-' || str[i] == '+'))
    {
      sign *= (str[i] == '-') * -1 + (str[i] == '+');
      ++i;
    }
  while (str[i] && str[i] >= '0' && str[i] <= '9')
    {
      nb = nb * 10 + (str[i] - 48);
      ++i;
    }
  return (nb * sign);
}
