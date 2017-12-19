/*
** my_printf.c for my_printf in /home/daniel_d/rendu/PSU_2013_my_printf
** 
** Made by daniel_d
** Login   <daniel_d@epitech.net>
** 
** Started on  Thu Nov 14 14:57:17 2013 daniel_d
** Last update Thu Jun 19 13:45:29 2014 daniel_d
*/

#include <stdarg.h>
#include <stdlib.h>
#include "../my.h"

void	my_printf_func(va_list ap, int f)
{
  void	(*tab[11])(va_list);
  tab[0] = &my_formatd;
  tab[1] = &my_formati;
  tab[2] = &my_formatb;
  tab[3] = &my_formato;
  tab[4] = &my_formatxmin;
  tab[5] = &my_formatxmaj;
  tab[6] = &my_formatp;
  tab[7] = &my_formatu;
  tab[8] = &my_formatc;
  tab[9] = &my_formats;
  tab[10] = &my_formatsmaj;
  tab[f](ap);
}

char	*my_printformat(char *my_formatall)
{
  my_formatall[0] = 'd';
  my_formatall[1] = 'i';
  my_formatall[2] = 'b';
  my_formatall[3] = 'o';
  my_formatall[4] = 'x';
  my_formatall[5] = 'X';
  my_formatall[6] = 'p';
  my_formatall[7] = 'u';
  my_formatall[8] = 'c';
  my_formatall[9] = 's';
  my_formatall[10] = 'S';
  return (my_formatall);
}

void	my_printf_funk(const char *format, char *my_formatall, va_list ap)
{
  int	a;
  int	f;

  f = 0;
  a = 0;
  while (format[a] != '\0')
    {
      if (format[a] == '%')
	{
	  while (my_formatall[f] != format[a + 1] && my_formatall[f] != 0)
	    f = f + 1;
	  if (format[a + 1] == my_formatall[f])
	    my_printf_func(ap, f);
	  else
	    {
	      my_putchar('%');
	      my_putchar(a + 1);
	    }
	  a = a + 2;
	  f = 0;
	}
      my_putchar(format[a]);
      a = a + 1;
    }
  free(my_formatall);
}

int	my_printf(const char *format, ...)
{
  va_list ap;
  char *my_formatall;

    my_formatall = malloc(sizeof(my_formatall) * 11);
  if (my_formatall == NULL)
    return (-1);
  if (format == NULL)
    return (-1);
  va_start(ap, format);
  my_formatall = my_printformat(my_formatall);
  my_printf_funk(format, my_formatall, ap);
  va_end(ap);
  return (0);
}
