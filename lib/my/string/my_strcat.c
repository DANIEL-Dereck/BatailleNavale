#include <stdlib.h>
#include "../my.h"

char    *my_strcat(char *src, char *str)
{
  char  *dest;
  int   a;
  int   b;
  int   i;
  int   l;

  i = 0;
  l = 0;
  a = my_strlen(src);
  b = my_strlen(str);
  if ((dest = malloc(sizeof(*dest) * (a + b))) == NULL)
    return (0);
  while (a >= 0)
    {
      dest[i] = src[i];
      i++;
      a--;
    }
  l = i;
  while (b >= 0)
    {
      dest[l++] = str[i++];
      b--;
    }
  return (dest);
}
