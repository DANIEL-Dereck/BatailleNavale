#include <stdlib.h>
#include "../my.h"

int     my_needposchar(char *str, char c)
{
  int   r;

  r = 0;
  if (str == NULL)
    return (-1);
  while (str[r] != '\0')
    {
      if (str[r] == c)
        return (r);
      r = r + 1;
    }
  return (-1);
}

int     my_needposcharAt(char *str, char c, int start)
{
  int   r;
  
  r = start;
  if (my_strlen(str) - start <= 0)
    return(-1);
  if (str == NULL)
    return (-1);
  while (str[r] != '\0')
    {
      if (str[r] == c)
        return (r);
      r = r + 1;
    }
  return (-1);
}