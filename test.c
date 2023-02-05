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
	while (*dst)
		dst++;
	while (*src)
		*dst++ = *src++;
	*dst = 0;
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

char *ft_strchr(char *str, char c)
{
	if (!str)
		return (NULL);
	while (*str)
	{
		if (*str == c)
			return (str);
		str++;
	}
	if (*str == c)
		return (str);
	return (NULL);
}

static char *ft_read_line(int fd, char *out, char *buffer)
{
	ssize_t len;
	char *tmp;
	
	len = 1;
	while (len != 0)
	{
		len = read(fd, out, BUFFER_SIZE);
		if (len < 1)
			return (NULL);
		out[len] = 0;
		if (!buffer)
			buffer = ft_calloc(1, 1);
		tmp = buffer;
		buffer = ft_strjoin(buffer, out);
		free(tmp);
		tmp = NULL;
		if(ft_strchr(buffer, '\n'))
			break ;
	}
	return (buffer);
}

char *ft_substr(char *str, size_t start, size_t len)
{
	char *out;
	size_t i;

	if (len > ft_strlen(str) - start)
	{
		out = ft_calloc(1, sizeof(char));
		if (!out)
			return (NULL);
		return (out);
	}
	out = (char *)malloc((len + 1) * sizeof(char));
	if (!out)
		return (NULL);
	i = 0;
	while (str[start] && i < len)
		out[i++] = str[start++];
	return (out);
}

static char *get_line(char *buffer)
{
	char *out;
	size_t count;

	count = 0;
	while (buffer[count] != '\n' && buffer[count] != '\0')
		count++;
	if (buffer[count] == '\0')
		return (buffer);
	out = ft_substr(buffer, count, ft_strlen(buffer) - count);
	if (!out)
		return (NULL);
	free(buffer);
	buffer = NULL;
	return (out);
}

char *get_next_line(int fd)
{
	static char *buf;
	char *out;

	out = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char)); 
	if (!out)
		return (NULL);
	buf = ft_read_line(fd, out, buf);
	if (!buf)
		return (NULL);
	free(out);
	out = NULL;
	buf = get_line(buf);
	return (buf);
}

int main()
{
	char *filename = "file.txt";
	int fd = open(filename, O_RDONLY);
	puts(get_next_line(fd));
	puts(get_next_line(fd));
	/* puts(ft_substr("hello world!", 5, 6)); */
	/* puts(ft_substr("hello world!", 5, 7)); */
	/* puts(ft_substr("hello world!", 5, 8)); */

	/* puts(ft_strjoin("hello ", "world!")); */


	return (0);
}
