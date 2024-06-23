/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscuderi <gscuderi@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 18:42:23 by gscuderi          #+#    #+#             */
/*   Updated: 2024/06/23 19:04:56 by gscuderi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t n_elem, size_t el_size)
{
	void	*ptr;
	size_t	tot;
	size_t	i;

	i = 0;
	tot = n_elem * el_size;
	if (n_elem && el_size && el_size > (UINT_MAX / n_elem))
		return (NULL);
	ptr = malloc(tot);
	while (i < tot)
		((unsigned char *)ptr)[i++] = '\0';
	return (ptr);
}

int		ft_strlen(const char *str)
{
	int	i;
	
	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int		i;
	
	i = 0;
	while (s && s[i])
	{
		if (s[i] == c)
			return (&s[i]);
		i++;
	}
	return (NULL);
}

 void	ft_strcat(char *dest, char *src)
 {
	int	j;
	int	i;

	j = 0;
	i = ft_strlen(dest);
	while (src[j])
	{
		dest[i + j] = src[j];
		src[j] = '\0';
		j++;
	}
	dest[i + j] = '\0';
 }