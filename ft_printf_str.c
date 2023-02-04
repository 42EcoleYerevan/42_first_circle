#include "libft.h"

int ft_printf_str(char *str)
{
	if (!str)
		return (write(1, "(null)", 6));
	return write(1, str, ft_strlen(str));
}
