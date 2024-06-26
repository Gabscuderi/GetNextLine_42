/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscuderi <gscuderi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 00:30:12 by gscuderi          #+#    #+#             */
/*   Updated: 2024/06/25 17:17:48 by gscuderi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

char	*get_next_line(int fd);
char	*ft_line_expand(char *base_buffer);
void	ft_create_line(char *base_buffer, char *mid_buffer);

int		ft_strlen(const char *str);
void	*ft_calloc(size_t n_elem, size_t el_size);
char	*ft_strchr(char *s, int c);
void	ft_strcat(char *dest, char *src);

#endif