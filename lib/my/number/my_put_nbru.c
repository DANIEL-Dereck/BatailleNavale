/*
** my_put_nbr.c for my_put_nbr.c in /home/daniel_d/rendu/Piscine-C-Jour_03
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Wed Oct  2 18:12:11 2013 daniel_d
** Last update Thu Jun 19 13:44:05 2014 daniel_d
*/

#include "../my.h"

void	my_whileu(unsigned int a, unsigned int c,
		  unsigned int d, unsigned int e)
{
  unsigned int nb;
  unsigned int z;

  nb = e;
  z = 0;
  if (nb < z)
    {
      my_putchar('-');
      nb = -nb;
      e = nb;
      d = nb;
    }

  while (nb > 9)
    {
      nb = nb / 10;
      a = a * 10;
    }
  while (a > z)
    {
      e = d / a;
      c = e % 10;
      my_putchar(c + 48);
      a = a / 10;
    }
}

int	my_put_nbru(unsigned int nb)
{
  unsigned int a;
  unsigned int c;
  unsigned int d;
  unsigned int e;

  a = 1;
  c = 1;
  d = nb;
  e = nb;
  my_whileu(a, c, d, e);
  return (0);
}

