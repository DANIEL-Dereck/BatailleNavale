#include <stdlib.h>
#include "../my.h"

char    *my_strdup(char *src)
{
  char  *dest;
  int   r;

  r = 0;
  if (src == NULL)
    return (NULL);
  while (src[r++] != '\0');
  if ((dest = malloc(sizeof(dest) * r)) == NULL)
    return (NULL);
  r = 0;
  while (src[r] != '\0')
    {
      dest[r] = src[r];
      r = r + 1;
    }
  dest[r] = '\0';
  return (dest);
}
