#include "ft_printf.h"

int ft_printf_select(va_list arg, const char *s)
{
	int out;

	out = 0;
	if (*s == 'd' || *s == 'i')
		out = ft_printf_digit(va_arg(arg, int));
	else if (*s == 'c')
		out = ft_printf_char(va_arg(arg, int));
	else if (*s == 's')
		out = ft_printf_str(va_arg(arg, char *));
	else if (*s == 'p')
		out = ft_printf_pointer(va_arg(arg, unsigned long long));
	else if (*s == 'u')
		out = ft_printf_unsigned(va_arg(arg, unsigned int));
	else if (*s == 'x' || *s == 'X')
		out = ft_printf_hex(va_arg(arg, unsigned long long), *s);
	else if (*s == '%')
		out = ft_printf_char('%');
	else
		out = write(1, s - 1, 2);
	return (out);
}

int ft_printf(const char *s, ...)
{
	int out;
	va_list arg;

	out = 0;
	va_start(arg, s);
	while (*s)
	{
		if (*s == '%' && *(s + 1))
		{
			s++;
			out += ft_printf_select(arg, s);
		}
		else
			out += write(1, s, 1);
		s++;
	}
	va_end(arg);
	return (out);
}
