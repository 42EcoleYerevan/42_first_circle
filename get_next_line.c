/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agladkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:47:38 by agladkov          #+#    #+#             */
/*   Updated: 2023/02/06 19:21:32 by agladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
		if (!buffer)
			return (NULL);
		free(tmp);
		tmp = NULL;
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
	static char	*buf;
	char		*out;

	out = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!out)
		return (NULL);
	buf = ft_read_line(fd, out, buf);
	if (!buf)
		return (NULL);
	out = get_line(buf);
	buf = get_buffer(buf);
	if (!out || !buf)
		return (NULL);
	return (out);
}
