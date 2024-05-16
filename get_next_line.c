/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscuderi <gscuderi@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 00:28:27 by gscuderi          #+#    #+#             */
/*   Updated: 2024/05/15 01:18:54 by gscuderi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ssize_t read(int fd, void buf[.count], size_t count);
//read gli dici quanti byte deve leggere e alloca in un buf,  
//when it reads 0 or less bytes, it should stop

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

char *ft_get_next_line(int fd)
{
int		bytes_read;
char	*cup_buffer;

cup_buffer = malloc((4+1) * sizeof(char));
if (!cup_buffer)
	return (NULL);
bytes_read = read(fd,cup_buffer, 4);
if (bytes_read <= 0)
	return (NULL);
return (cup_buffer);
}

