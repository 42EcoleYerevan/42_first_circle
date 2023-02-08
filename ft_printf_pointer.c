#include "ft_printf.h"

void ft_putptr(unsigned long long num)
{
	if (num > 16)
	{
		ft_putptr(num / 16);
		ft_putptr(num % 16);
	}
	else if (num < 10)
		ft_printf_char(num + '0');
	else if (num < 17)
		ft_printf_char(num - 10 + 'a');
}

int ft_lenptr(unsigned long long num)
{
	int out;

	out = 0;
	while (num)
	{
		out++;
		num /= 16;
	}
	return (out);
}

int ft_printf_pointer(unsigned long long num)
{
	int out;

	out = 0;
	if (num == 0)
		return (write(1, "(nil)", 5));
	else
	{
		out += write(1, "0x", 2);
		ft_putptr(num);
		out += ft_lenptr(num);
	}
	return (out);
}
