#include <stdlib.h>
#include "../my.h"

int     my_strcmp(char *s1, char *s2)
{
  int b;
  int c;

  b = my_strlen(s1);
  c = my_strlen(s2);
  if (s1 == NULL || s2 == NULL)
    return (-1);
  if (b != c)
    return (-1);
  b = 0;
  while (s1[b] != '\0')
    {
      if (s1[b] != s2[b])
        return (-1);
      b++;
    }
  return (0);
}
