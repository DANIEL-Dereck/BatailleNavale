/*
** my_format3.c for my_printf in /home/daniel_d/rendu/PSU_2013_my_printf
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Sun Nov 17 14:02:46 2013 daniel_d
** Last update Thu Jun 19 13:45:09 2014 daniel_d
*/

#include <stdarg.h>
#include "../my.h"

void	my_formatsmaj(va_list ap)
{
  my_putstr(va_arg(ap, char *));
}
