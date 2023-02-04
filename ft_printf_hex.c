#include "libftprintf.h"

int ft_printf_lenhex(unsigned int n)
{
	int out;

	out = 0;
	while (n)
	{
		out++;
		n /= 16;
	}
	if (out == 0)
		return (1);
	return (out);
}

void ft_printf_puthex(unsigned int n, int c)
{
	if (n < 10)
		ft_printf_char(n + '0');
	else if (n < 17)
	{
		if (c == 'x')
			ft_printf_char(n - 10 + 'a');
		else if (c == 'X')
			ft_printf_char(n - 10 + 'A');
	}
	else
	{
		ft_printf_puthex(n / 16, c);
		ft_printf_puthex(n % 16, c);
	}
}

int ft_printf_hex(unsigned int n, int c)
{
	ft_printf_puthex(n ,c);
	return (ft_printf_lenhex(n));
}
