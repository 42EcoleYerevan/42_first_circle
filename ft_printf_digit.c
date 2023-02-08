#include "ft_printf.h"

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
	int out;
	out = 0;
	if (d == -2147483648)
		return (write(1, "-2147483648", 11));
	if (d < 0)
	{
		out += write(1, "-", 1);
		d = -d;
	}
	ft_printf_putint(d);
	out += ft_printf_lenint(d);
	return (out);
}
