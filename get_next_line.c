/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscuderi <gscuderi@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 00:28:27 by gscuderi          #+#    #+#             */
/*   Updated: 2024/05/21 00:28:33 by gscuderi         ###   ########.fr       */
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

char    *ft_read_from_file(char *base_buffer, int fd);
char    *ft_create_line(char *base_buffer);
char    *ft_manage_remaining(char *base_buffer);
char    *ft_attach_buffer(char *base_buffer, char *mid_buffer);

char	*get_next_line(int fd)
{
	static char *base_buffer;
    char        *one_line;
    
    if (fd <0 || read(fd, NULL, 0) < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    if (!base_buffer)
        base_buffer = malloc(1 * sizeof(char));
    if (!ft_strchr(base_buffer, '\n'))
        base_buffer = ft_read_from_file(base_buffer, fd);
    if(!base_buffer)
        return (free(base_buffer), NULL);
	one_line = ft_create_line(base_buffer);
    base_buffer = ft_manage_remaining(base_buffer); 
	return (base_buffer);
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
        if (!ft_strchr(base_buffer, '\n'))
            break;
    }
    free(mid_buffer);
    return(base_buffer);
}

char    *ft_create_line(char *base_buffer)
{
    //copia base in str compreso il \n mettondo un \0, e non il resto
  //ritorna come one_line nel get_next_line
}

char    *ft_manage_remaining(char *base_buffer)
{
    //toglie dal buffer il pre \n e ci lascia cio che rimane, 
  //ritorna come nuova base da riempire in get
}

char    *ft_attach_buffer(char *base_buffer, char *mid_buffer)
{
    char    *tmp;
    
    tmp = ft_strjoin(base_buffer, mid_buffer);
    free(base_buffer);
    return (tmp);
}

