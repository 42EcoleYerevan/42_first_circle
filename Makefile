NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar r
OBJS = ft_printf_char.o\
	   ft_printf_str.o\
	   ft_printf_digit.o\
	   ft_printf_pointer.o\
	   ft_printf_unsigned.o\
	   ft_printf_hex.o\
	   ft_printf.o
HEADER = ft_printf.h

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(HEADER)
	$(AR) $(NAME) $(OBJS)

all: $(NAME)

clean: $(OBJS)
	rm -rf $(OBJS)

fclean: clean $(NAME)
	rm -rf $(NAME)

re: clean fclean all

.PHONY: all clean fclean re
