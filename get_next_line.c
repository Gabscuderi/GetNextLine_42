/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscuderi <gscuderi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 00:28:27 by gscuderi          #+#    #+#             */
/*   Updated: 2024/06/09 17:56:07 by gscuderi         ###   ########.fr       */
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

char	*ft_read_from_file(char *base_buffer, int fd);
char	*ft_create_line(char *base_buffer, int *ptr_counter);
char	*ft_manage_remaining(char *base_buffer);
char	*ft_attach_buffer(char *base_buffer, char *mid_buffer);

char	*get_next_line(int fd)
{
	static char	*base_buffer;
	char 		*one_line;
	int			counter_line;

	counter_line = 0;
	if (fd < 0 || read(fd, NULL, 0) < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!base_buffer)
		base_buffer = malloc(1 * sizeof(char));
	if (!ft_strchr(base_buffer, '\n'))
		base_buffer = ft_read_from_file(base_buffer, fd);
	if(!base_buffer)
		return (free(base_buffer), NULL);
	one_line = ft_create_line(base_buffer, &counter_line);
	base_buffer = ft_manage_remaining(base_buffer); 
	return (one_line);
}


char *ft_read_from_file(char *base_buffer, int fd)
{
	int		bytes_read;
	char	*mid_buffer;


	mid_buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!mid_buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, mid_buffer,   BUFFER_SIZE);
		if (bytes_read < 0) //if nothing read
			return (free(mid_buffer), NULL);
		//if smt has been read
		mid_buffer[BUFFER_SIZE + 1] = '\0';
		base_buffer = ft_attach_buffer(base_buffer, mid_buffer);
		//free what comes back from attach but it means it should be static
		if (ft_strchr(base_buffer, '\n') != NULL ) //se trovo il \n torno a get e creo linea e gestisco rimanenti 
			break;
	}
	free(mid_buffer);
	return(base_buffer);
}

char 	*ft_create_line(char *base_buffer, int *ptr_counter) //torna one_line
{
	char	*line;

	while (base_buffer)
	{
		*line = *base_buffer;
		if ((*line) == '\n')
			break;
		line++;
		base_buffer++;
	}
	*ptr_counter += 1;
	return (line);
}

//counter is i of create line so it's the char after \n
char    *ft_manage_remaining(char *base_buffer)
{
	char	*tmp;

	tmp = malloc(1 * sizeof(char));
	while (*base_buffer != '\n')
		base_buffer++;
	while (*base_buffer != '\0')
		*tmp = *base_buffer;
	return (tmp);
}

char    *ft_attach_buffer(char *base_buffer, char *mid_buffer)
{
	char    *tmp;
	
	tmp = ft_strjoin(base_buffer, mid_buffer);
	free(base_buffer);
	return (tmp);
}

