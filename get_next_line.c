/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscuderi <gscuderi@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 00:28:27 by gscuderi          #+#    #+#             */
/*   Updated: 2024/05/20 20:02:42 by gscuderi         ###   ########.fr       */
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

void    print_newline_helper(char *buffer)
{

    while (*buffer &&  *buffer != '\0')
    {
        if (*buffer == '\n') 
        {
            *buffer= '\\';
        }
        printf("%c",*buffer);
        buffer++;
    }
}

char *ft_read_from_file(int fd)
{
int		bytes_read;
char	*cup_buffer;
static int	count = 1;

printf("malloc#[%d]---", count++);
cup_buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
if (!cup_buffer)
	return (NULL);
bytes_read = read(fd,cup_buffer, BUFFER_SIZE);
if (bytes_read <= 0)
	return (NULL);
return (cup_buffer);
}

char	*get_next_line(int fd)
{
	static char *base_buffer;

	base_buffer = ft_read_from_file(fd);
	return (base_buffer);
}

