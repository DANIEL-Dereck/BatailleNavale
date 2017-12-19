/*
** my_format2.c for my_printf in /home/daniel_d/rendu/PSU_2013_my_printf
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Sun Nov 17 11:55:52 2013 daniel_d
** Last update Thu Jun 19 13:45:00 2014 daniel_d
*/

#include <stdarg.h>
#include "../my.h"

void    my_formatxmaj(va_list ap)
{
  my_putnbr_base(va_arg(ap, int), "01234567899ABCDEF");
}

void	my_formatp(va_list ap)
{
  my_putstr("0x");
  my_putstr(va_arg(ap, char*));
}

void	my_formatu(va_list ap)
{
  my_put_nbru(va_arg(ap, unsigned int));
}

void	my_formatc(va_list ap)
{
  my_putchar(va_arg(ap, int));
}

void	my_formats(va_list ap)
{
  my_putstr(va_arg(ap, char *));
}

