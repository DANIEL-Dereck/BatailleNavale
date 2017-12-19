/*
** my_format.c for my_printf in /home/daniel_d/rendu/PSU_2013_my_printf
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Sun Nov 17 11:32:10 2013 daniel_d
** Last update Thu Jun 19 13:45:19 2014 daniel_d
*/

#include <stdarg.h>
#include "../my.h"

void	my_formatd(va_list ap)
{
  my_put_nbr(va_arg(ap, int));
}

void	my_formati(va_list ap)
{
  my_put_nbr(va_arg(ap, int));
}

void	my_formatb(va_list ap)
{
  my_putnbr_base(va_arg(ap, int), "01");
}

void	my_formato(va_list ap)
{
  my_putnbr_base(va_arg(ap, int), "01234567");
}

void	my_formatxmin(va_list ap)
{
  my_putnbr_base(va_arg(ap, int), "01234567899abcdef");
}

