#include <stdio.h>
#include <stdlib.h>
#include "ft_printf.h"

int main()
{
	/* int p[] = {1, 2}; */
	/* int a = 123; */
	/* int orig = printf("decimal or integer %d\nchar %c\nstring %s\npointer %p\nunsigned %u\nlower hex %x\nupper hex %X\n",\ */
	/* 										-2147483647, 'l', 	"hello world!", p, 		4294967295, &a, 		NULL); */
	/* int mine = ft_printf("decimal or integer %d\nchar %c\nstring %s\npointer %p\nunsigned %u\nlower hex %x\nupper hex %X\n",\ */
	/* 										-2147483648, 		'l', 	"hello world!", p, 	4294967295, &a, 			NULL); */
	/* int orig_null = printf("decimal or integer %d\nchar %c\nstring %s\npointer %p\nunsigned %u\nlower hex %x\nupper hex %X\n",\ */
	/* 											NULL, 	NULL, 		NULL, 		NULL, 		NULL, 			NULL, 		NULL); */
	/* int mine_null = ft_printf("decimal or integer %d\nchar %c\nstring %s\npointer %p\nunsigned %u\nlower hex %x\nupper hex %X\n",\ */
	/* 											NULL, 		NULL, 		NULL, 		NULL, 		NULL, 			NULL, 		NULL); */

	/* printf("\033[2J\033[2H"); */
	/* printf("%d %d\n", orig, mine); */
	/* printf("%d %d\n", orig_null, mine_null); */
	/* if (orig == mine) */
	/* 	printf("ok!\n"); */
	/* if (orig_null == mine_null) */
	/* 	printf("ok!\n"); */

	int i = ft_printf("%p\n", NULL);
	printf("%p\n", NULL);


	return (0);
}
