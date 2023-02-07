#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"

int main()
{
	int fd = open("file.txt", O_RDONLY);
	puts(get_next_line(fd));
	puts(get_next_line(fd));
	puts(get_next_line(fd));
	puts(get_next_line(fd));
	puts(get_next_line(fd));

	return (0);
}
