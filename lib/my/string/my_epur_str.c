#include <stdlib.h>
#include "../my.h"

char    *my_remp_str(char *str, char *dest, int i, int k)
{
  i = 0;
  k = 0;
  while (str[i] != '\0')
    {
      if (str[i] == ' ' || str[i] == '\t')
        {
          while (str[i] == ' ' || str[i] == '\t' || str[i] == '\0')
            i++;
          dest[k++] = str[i++];
        }
      else
        dest[k++] = str[i++];
    }
  dest[k] = '\0';
  return (dest);
}

char    *my_epur_str(char *str)
{
  char  *dest;
  int   k;
  int   i;

  k = 0;
  i = 0;
  if (str == NULL)
    return (NULL);
  while (str[i] != '\0')
    {
      if (str[i] == ' ' || str[i] == '\t')
        while (str[i] == ' ' || str[i] == '\t' || str[i] == '\0')
          i++;
      else
        i++;
      k++;
    }
  if ((dest = malloc(sizeof(*dest) * (k + 1))) == NULL)
    return (NULL);
  dest = my_remp_str(str, dest, i, k);
  return (dest);
}
