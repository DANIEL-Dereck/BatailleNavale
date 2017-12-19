#include "../my.h"

void    my_basewhile(int c, int d, int ba, char *base)
{
  int nb;
  int a;
  int e;

  a = 1;
  nb = d;
  e = d;
  while (nb >= ba)
    {
      nb = nb / ba;
      a = a * ba;
    }
  while (a > 0)
    {
      e = d / a;
      c = e % ba;
      my_putchar(base[c]);
      a = a / ba;
    }
}

int     my_putnbr_base(int nb, char *base)
{
  int c;
  int d;
  int ba;

  if (base == NULL)
    return (-1);
  ba = my_strlen(base);
  if (nb < 0)
    {
      my_putchar('-');
      nb = -nb;
    }
  c = 1;
  d = nb;
  my_basewhile(c, d, ba, base);
  return (0);
}

int     my_putnbr_base_rec(int nb, char *base)
{
  int   c;

  if (base == NULL)
    return (-1);
  c = my_strlen(base);
  if (nb < 0)
    {
      my_putchar('-');
      nb = -nb;
    }
  if (nb >= c)
    {
      my_putnbr_base_rec(nb / c, base);
      my_putnbr_base_rec(nb % c, base);
    }
  else
    my_putchar(base[c]);
  return (0);
}