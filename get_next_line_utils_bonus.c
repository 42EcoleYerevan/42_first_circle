/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agladkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:50:55 by agladkov          #+#    #+#             */
/*   Updated: 2023/02/07 18:17:31 by agladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_calloc(size_t count, size_t size)
{
	char	*out;

	out = (char *)malloc(count * size);
	if (!out)
		return (NULL);
	while (count > 0)
		out[--count] = 0;
	return (out);
}

size_t	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (*str)
	{
		len++;
		str++;
	}
	return (len);
}

char	*ft_strcat(char *dst, char *src)
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

char	*ft_strjoin(char *str1, char *str2)
{
	char	*out;

	out = ft_calloc((ft_strlen(str1) + ft_strlen(str2) + 1), sizeof(char));
	if (!out)
		return (NULL);
	ft_strcat(out, str1);
	ft_strcat(out, str2);
	return (out);
}

char	*ft_substr(char *str, size_t start, size_t len)
{
	char	*out;
	size_t	i;

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
	out[i] = 0;
	return (out);
}
