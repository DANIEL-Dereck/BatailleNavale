#include <stdlib.h>
#include "../my.h"

int	my_strlen(char *str)
{
  int a;

  a = 0;
  if (str == NULL)
    return (-1);
  while (str[a++] != '\0');
  a--;
  return (a);
}
