#include <stdio.h>
#include <stdlib.h>
#include "libftprintf.h"
#include "libft.h"

int main()
{
	int p[] = {1, 2};
	int a = 123;
	int orig = printf("decimal or integer %d\nchar %c\nstring %s\npointer %p\nunsigned %u\nlower hex %x\nupper hex %X\n",\
											-1234, 'l', 	"hello world!", p, 			-1, 			&a, 		NULL);
	int mine = ft_printf("decimal or integer %d\nchar %c\nstring %s\npointer %p\nunsigned %u\nlower hex %x\nupper hex %X\n",\
											-1234, 		'l', 	"hello world!", p, 			-1, 		&a, 			NULL);
	int orig_null = printf("decimal or integer %d\nchar %c\nstring %s\npointer %p\nunsigned %u\nlower hex %x\nupper hex %X\n",\
												NULL, 	NULL, 		NULL, 		NULL, 		NULL, 			NULL, 		NULL);
	int mine_null = ft_printf("decimal or integer %d\nchar %c\nstring %s\npointer %p\nunsigned %u\nlower hex %x\nupper hex %X\n",\
												NULL, 		NULL, 		NULL, 		NULL, 		NULL, 			NULL, 		NULL);

	printf("\033[2J\033[2H");
	if (orig == mine)
		printf("ok!\n");
	if (orig_null == mine_null)
		printf("ok!\n");
	return (0);
}
