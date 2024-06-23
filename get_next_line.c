/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscuderi <gscuderi@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 00:28:27 by gscuderi          #+#    #+#             */
/*   Updated: 2024/06/23 16:20:04 by gscuderi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ssize_t read(int fd, void buf[.count], size_t count);
//read gli dici quanti byte deve leggere e alloca in un buf,  
//when it reads 0 or less bytes, it should stop
//base_buffer e mid_buffer.
//base diventa line, a \n at the time

#include "get_next_line.h"

void	ft_create_line(char *base_buffer, char *mid_buffer);
char	*ft_line_expand(char *base_buffer);

char	*get_next_line(int fd)
{
	static char		mid_buffer[BUFFER_SIZE + 1];
	char			*base_buffer;
	int 			bytes_read;
	
	bytes_read = 1;
	base_buffer = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (!ft_strchr(base_buffer, '\n'))
	{
		if (!*mid_buffer)
			bytes_read = read(fd, mid_buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			break;
		base_buffer = ft_line_expand(base_buffer);
		ft_create_line(base_buffer, mid_buffer);
	}
	if (base_buffer && *base_buffer)
		return (base_buffer);
	return (free(base_buffer), NULL);
}

//base_buffer goes in 
//mem. of base will be expand when
//we allocate new mem. for line.
//the ft returns line and frees the base
//line returns in get_next_line as the new base.
char	*ft_line_expand(char *base_buffer) 
{
	char	*line;

	line = ft_calloc((ft_strlen(base_buffer) + BUFFER_SIZE + 1), sizeof(char));
	if (!line)
		return (NULL);
	if (base_buffer)//if its not end of fd
		ft_strcat(line, base_buffer);
	return (free(base_buffer), line);
} 

//for ft_create_line we can mixe it wiht ft_strcat
//mid will be append to base, but here if the \n will be append 
// we break it, and as in ft_strcat what's each time we put a null 
//in the mid memory we just copied, so at the end mid will only 
//have what's next the \n
void	ft_create_line(char *base_buffer, char *mid_buffer) //torna one_line
{
	int	i;
	int	j;

	j = 0;
	i = ft_strlen(base_buffer);
	while (mid_buffer[j] || base_buffer[i + j -1] == '\n')
	{
		base_buffer[i + j] = mid_buffer[j];
		mid_buffer[j] = '\0';
		j++;
	}
	if (mid_buffer[j])
		ft_strcat(mid_buffer, mid_buffer + j);
}

/*
char	*ft_read_from_file(char *base_buffer, int fd);

char	*get_next_line(int fd)
{
	static char	*base_buffer;
	char 		*one_line;

	if (fd < 0 || read(fd, NULL, 0) < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!base_buffer)
		base_buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
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


	mid_buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
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
*/