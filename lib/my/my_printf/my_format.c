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
  my_putnbr_base(va_arg(ap, int), BINARY);
}

void	my_formato(va_list ap)
{
  my_putnbr_base(va_arg(ap, int), OCTAL);
}

void	my_formatxmin(va_list ap)
{
  my_putnbr_base(va_arg(ap, int), HEXAMIN);
}

void    my_formatxmaj(va_list ap)
{
  my_putnbr_base(va_arg(ap, int), HEXAMAX);
}

void	my_formatp(va_list ap)
{
  my_putstr(OX);
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

void	my_formatsmaj(va_list ap)
{
  my_putstr(va_arg(ap, char *));
}