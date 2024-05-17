/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscuderi <gscuderi@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 00:28:27 by gscuderi          #+#    #+#             */
/*   Updated: 2024/05/17 10:32:48 by gscuderi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ssize_t read(int fd, void buf[.count], size_t count);
//read gli dici quanti byte deve leggere e alloca in un buf,  
//when it reads 0 or less bytes, it should stop

//base_buffer e cup_buffer.
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "get_next_line.h"

char *ft_get_next_line(int fd)
{
int		bytes_read;
char	*cup_buffer;
static int	count = 1;

printf("ft_calloc#[%d]---", count++);
cup_buffer = malloc((3 + 1) * sizeof(char));
if (!cup_buffer)
	return (NULL);
bytes_read = read(fd,cup_buffer, 3);
if (bytes_read <= 0)
	return (NULL);
return (cup_buffer);
}

