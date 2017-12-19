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
