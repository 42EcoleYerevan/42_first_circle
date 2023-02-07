/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agladkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:47:38 by agladkov          #+#    #+#             */
/*   Updated: 2023/02/07 20:21:24 by agladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char *str, char c)
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

static char	*ft_read_line(int fd, char *out, char *buffer)
{
	ssize_t	len;
	char	*tmp;

	len = 1;
	while (len != 0)
	{
		len = read(fd, out, BUFFER_SIZE);
		if (len < 1)
			break ;
		out[len] = 0;
		if (!buffer)
			buffer = ft_calloc(1, 1);
		tmp = buffer;
		buffer = ft_strjoin(buffer, out);
		free(tmp);
		tmp = NULL;
		if (!buffer)
			return (NULL);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (buffer);
}

char	*get_line(char *buffer)
{
	size_t	len;
	char	*out;

	len = 0;
	while (buffer[len] != '\n' && buffer[len] != '\0')
		len++;
	out = ft_substr(buffer, 0, len);
	if (!out)
		return (NULL);
	return (out);
}

static char	*get_buffer(char *buffer)
{
	char	*tmp;
	size_t	len;

	len = 0;
	while (buffer[len] != '\n' && buffer[len] != '\0')
		len++;
	len++;
	tmp = buffer;
	buffer = ft_substr(buffer, len, ft_strlen(buffer) - len);
	if (!buffer)
		return (NULL);
	free(tmp);
	tmp = NULL;
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buf[4096];
	char		*out;

	out = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!out)
		return (NULL);
	buf[fd] = ft_read_line(fd, out, buf[fd]);
	if (!buf[fd])
		return (NULL);
	out = get_line(buf[fd]);
	buf[fd] = get_buffer(buf[fd]);
	if (!out || !buf[fd])
		return (NULL);
	return (out);
}
