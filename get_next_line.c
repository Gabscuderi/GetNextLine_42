/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscuderi <gscuderi@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 00:28:27 by gscuderi          #+#    #+#             */
/*   Updated: 2024/06/19 20:08:31 by gscuderi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ssize_t read(int fd, void buf[.count], size_t count);
//read gli dici quanti byte deve leggere e alloca in un buf,  
//when it reads 0 or less bytes, it should stop

//base_buffer e mid_buffer.
//base diventa line, a \n at the time

#include "get_next_line.h"

char	*ft_read_from_file(char *base_buffer, int fd);
char	*ft_create_line(char *base_buffer);

char	*get_next_line(int fd)
{
	static char	*base_buffer;
	char 		*one_line;

	if (fd < 0 || read(fd, NULL, 0) < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!base_buffer)
		base_buffer = malloc(1 * sizeof(char));
	if (!ft_strchr(base_buffer, '\n'))
		base_buffer = ft_read_from_file(base_buffer, fd);
	if(!base_buffer)
	{
		free(base_buffer);
		return (NULL);
	}
	one_line = ft_create_line(base_buffer);
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
		if (bytes_read < 0)
		{
			free(mid_buffer);
			return (NULL);
		}
		mid_buffer[BUFFER_SIZE + 1] = '\0';
		ft_strcat(base_buffer, mid_buffer);
		if (ft_strchr(base_buffer, '\n') != NULL )
			break;
	}
	return(base_buffer);
}

char 	*ft_create_line(char *base_buffer) //torna one_line
{
	char	*line;
	int		i;

	i = 0;
	line = malloc((ft_strlen(base_buffer) + 1) * sizeof(char *));
	if (!line)
		return NULL;
	while (line[i - 1] == '\n' || base_buffer)
	{
		line[i] = *base_buffer;
		i++;
		base_buffer++;
	}
	line[i] = '\0';
	return (line);
}
