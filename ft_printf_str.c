#include "ft_printf.h"

size_t ft_strlen(const char *s)
{
	size_t len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

int ft_printf_str(char *str)
{
	if (!str)
		return (write(1, "(null)", 6));
	return write(1, str, ft_strlen(str));
}
