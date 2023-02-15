/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agladkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:48:46 by agladkov          #+#    #+#             */
/*   Updated: 2023/02/06 16:50:42 by agladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*rebuffer(char *buffer);
char *bufferjoin(char *buffer, char *str);
char	*read_line(int fd, char *buffer);
char	*get_line(char *buffer);
char	*ft_calloc(size_t count, size_t size);
size_t	ft_strlen(char *str);
char	*ft_strcat(char *dst, char *src);
char	*ft_strjoin(char *str1, char *str2);
char	*ft_strchr(char *str, char c);
char	*ft_substr(char *s, size_t start, size_t len);
char	*get_next_line(int fd);

#endif
