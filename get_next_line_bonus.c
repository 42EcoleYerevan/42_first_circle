/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agladkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:47:38 by agladkov          #+#    #+#             */
/*   Updated: 2023/02/07 20:20:31 by agladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char *bufferjoin(char *buffer, char *str)
{
	char *tmp;

	if (!buffer)
		buffer = (char *)ft_calloc(1, 1);
	tmp = buffer;
	buffer = ft_strjoin(buffer, str);
	free(tmp);
	tmp = NULL;
	return (buffer);
}

char	*read_line(int fd, char *buffer)
{
	ssize_t	len;
	char *out;
	int buffersize;

	buffersize = (BUFFER_SIZE == 1)? 100: BUFFER_SIZE;
	out = (char *)malloc((buffersize + 1) * sizeof(char));
	len = 1;
	while (len > 0)
	{
		len = read(fd, out, buffersize);
		if ((ft_strlen(buffer) == 0 && len == 0) || len < 0)
		{
			free(out);
			return (NULL);
		}
		out[len] = 0;
		buffer = bufferjoin(buffer, out);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(out);
	return (buffer);
}

char	*rebuffer(char **buffer)
{
	char	*tmp;
	char 	*out;
	char 	*line;
	size_t	len;

	len = 0;
	out = (char *)*buffer;
	while (out[len] != '\n' && out[len] != '\0')
		len++;
	if (out[len] == '\n')
		len++;
	tmp = out;
	line = ft_substr(out, 0, len);
	*buffer = ft_substr(out, len, ft_strlen(out) - len);
	free(tmp);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buf[4096];
	char *out;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
		return (NULL);
	buf[fd] = read_line(fd, buf[fd]);
	if (!buf[fd])
		return (NULL);
	out = rebuffer(&buf[fd]);
	if (!buf[fd])
	{
		free(out);
		return (NULL);
	}
	return (out);
}
