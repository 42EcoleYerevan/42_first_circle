#include "libftprintf.h"

void ft_printf_putint(int n)
{
	if (n < 10)
		ft_printf_char(n + '0');
	else
	{
		ft_printf_putint(n / 10);
		ft_printf_putint(n % 10);
	}
}

int ft_printf_lenint(int n)
{
	int out;

	out = 0;
	while (n)
	{
		out++;
		n /= 10;
	}
	if (out == 0)
		return (1);
	return (out);
}

int ft_printf_digit(int d)
{
	ft_printf_putint(d);
	return (ft_printf_lenint(d));
}
