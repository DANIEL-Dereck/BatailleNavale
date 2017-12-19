#include "../my.h"

void	my_while(int a, int c, int d, int e)
{
  int nb;

  nb = e;
  if (nb < 0)
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
  while (a > 0)
    {
      e = d / a;
      c = e % 10;
      my_putchar(c + 48);
      a = a / 10;
    }
}

int	my_put_nbr(int nb)
{
  int a;
  int c;
  int d;
  int e;

  a = 1;
  c = 1;
  d = nb;
  e = nb;
  my_while(a, c, d, e);
  return (0);
}

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