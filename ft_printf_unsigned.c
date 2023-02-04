#include "libftprintf.h"

int ft_printf_lenuint(unsigned int num)
{
	int out;

	out = 0;
	while (num)
	{
		out++;
		num /= 10;
	}
	if (out == 0)
		return (1);
	return (out);
}

void ft_printf_putuint(unsigned int n)
{
	if (n < 10)
		ft_printf_char(n + '0');
	else
	{
		ft_printf_putuint(n / 10);
		ft_printf_putuint(n % 10);
	}
}


int ft_printf_unsigned(unsigned int n)
{
	ft_printf_putuint(n); 
	return (ft_printf_lenuint(n));
}
