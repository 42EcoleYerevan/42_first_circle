#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 10

char *ft_calloc(size_t count, size_t size)
{
	char *out;

	out = (char *)malloc(count * size);
	if (!out)
		return (NULL);
	while (count > 0)
		out[--count] = 0;
	return (out);
}

size_t ft_strlen(char *str)
{
	int len;

	len = 0;
	while (*str)
	{
		len++;
		str++;
	}
	return (len);
}

char *ft_strcat(char *dst, char *src)
{
	if (!dst || !src)
		return (NULL);
	if (src == dst)
		return (dst);
	while (*src)
		*dst++ = *src++;
	return (dst);
}

char *ft_strjoin(char *str1, char *str2)
{
	char *out;

	out = ft_calloc((ft_strlen(str1) + ft_strlen(str2) + 1), sizeof(char));
	if (!out)
		return (NULL);
	ft_strcat(out, str1);
	ft_strcat(out, str2);
	return (out);
}

char *get_next_line(int fd)
{
	ssize_t len;
	char *out;

	out = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char)); 
	len = read(fd, out, BUFFER_SIZE);
	return (out);
}

int main()
{
	char *filename = "file.txt";
	int fd = open(filename, O_RDONLY);
	char *str;
	str = get_next_line(fd);
	puts(str);

	return (0);
}
