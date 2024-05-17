/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscuderi <gscuderi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 19:49:29 by gscuderi          #+#    #+#             */
/*   Updated: 2024/05/17 20:06:26 by gscuderi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(void)
{
	int		fd;
	char	*line;
	int		count;

	count = 0;
	fd = open("testo_prova.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Error opening file");
		return(1);
	}
	while (1)
	{
		line = ft_get_next_line(fd);
		if (line == NULL)
			break;
		count++;
		printf("[%d]:%s\n", count, line);
		free(line);
		line = NULL;
	}

	close(fd);
	return (0);
}