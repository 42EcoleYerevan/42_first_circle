#include "libft.h"

int ft_printf_str(char *str)
{
	return write(1, str, ft_strlen(str));
}
