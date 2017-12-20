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