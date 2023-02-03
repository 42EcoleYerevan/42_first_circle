#include "libft.h"

int ft_printf_digit(int d)
{
	char *str;

	str = ft_itoa(d);
	return write(1, str, ft_strlen(str));
}
