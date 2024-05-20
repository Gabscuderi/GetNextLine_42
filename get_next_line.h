/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscuderi <gscuderi@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 00:30:12 by gscuderi          #+#    #+#             */
/*   Updated: 2024/05/21 00:33:10 by gscuderi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 3
#endif

# include <unistd.h>

char	*get_next_line(int fd);

char    *ft_read_from_file(char *base_buffer, int fd);
char    *ft_create_line(char *base_buffer);
char    *ft_manage_remaining(char *base_buffer);
char    *ft_attach_buffer(char *base_buffer, char *mid_buffer);

void	*ft_calloc(size_t n_elem, size_t el_size);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);

int main(void);

#endif