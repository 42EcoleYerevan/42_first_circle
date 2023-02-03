#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <unistd.h>

int ft_printf_digit(int d);
int ft_printf_char(char c);
int ft_printf_str(char *str);
int ft_printf_pointer(unsigned long long num);

#endif
