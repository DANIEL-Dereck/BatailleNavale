/*
** my_put_nbr_rec.c for rec2 in /home/daniel_d/Name_Prog/Lib/lib/my
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Tue Dec 10 12:53:14 2013 daniel_d
** Last update Thu Jun 19 13:44:36 2014 daniel_d
*/

#include "../my.h"

int     my_put_nbr_rec(int nb)
{
  if (nb < 0)
    {
      my_putchar('-');
      nb = -nb;
    }
  if (nb >= 9)
    {
      my_put_nbr_rec(nb / 10);
      my_put_nbr_rec(nb % 10);
    }
  else
    my_putchar(nb + 48);
  return (0);
}
