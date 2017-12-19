#include "../my.h"

int	my_pow(int nbr, int puissance)
{
  int	nbrs;

  nbrs = nbr;
  if (puissance == 0)
    nbr = 1;
  else if (puissance == 1)
    nbr = nbr;
  else
    while (puissance > 1)
      {
	nbr = nbr * nbrs;
	puissance--;
      }
  return (nbr);
}
