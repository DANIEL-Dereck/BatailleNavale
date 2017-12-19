/*
** my_putchar.c for my_putchar.c in /home/daniel_d/rendu/Piscine-C-lib/my
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Mon Oct 21 10:28:12 2013 daniel_d
** Last update Thu Jun 19 13:42:08 2014 daniel_d
*/

#include <unistd.h>
#include "../my.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}
