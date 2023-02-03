#include <unistd.h>

int ft_printf_char(char c)
{
	return write(1, &c, 1);
}
