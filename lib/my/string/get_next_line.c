/*
** get_next_line.c for get_next_line in /home/daniel_d/rendu/get_next_line-2018-daniel_d
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Tue Nov 19 11:43:10 2013 daniel_d
** Last update Thu Jun 19 13:40:50 2014 daniel_d
*/

#include <unistd.h>
#include <stdlib.h>
#include "../my.h"

char    *add_char_in_line(char *line, char c)
{
  int   i;
  char  *new_line;

  i = 0;
  if ((new_line = malloc(sizeof(*new_line) * (my_strlen(line) + 2))) == NULL)
    return (NULL);
  while (line && line[i])
    {
      new_line[i] = line[i];
      i++;
    }
  new_line[i] = c;
  new_line[++i] = 0;
  if (line != NULL)
    free(line);
  return (new_line);
}

char    *get_next_line(int fd)
{
  char  *line;
  int	r;
  char  c;
  char  s;

  s = '\0';
  line = NULL;
  while ((r = read(fd, &c, 1)) && (c != '\0' && s != '\n'))
    {
      if (c =='\n')
	{
	  if (line != NULL)
	    return (line);
	  else
	    line = "\0";
	  return (line);
	}
      if ((line = add_char_in_line(line, c)) == NULL)
	return (NULL);
      s = c;
    }
  return (line);
}
