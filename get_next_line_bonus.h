/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agladkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 18:16:29 by agladkov          #+#    #+#             */
/*   Updated: 2023/02/07 18:16:35 by agladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*ft_calloc(size_t count, size_t size);
size_t	ft_strlen(char *str);
char	*ft_strcat(char *dst, char *src);
char	*ft_strjoin(char *str1, char *str2);
char	*ft_strchr(char *str, char c);
char	*ft_substr(char *str, size_t start, size_t len);
char	*get_next_line(int fd);

#endif
