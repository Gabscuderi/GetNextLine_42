/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscuderi <gscuderi@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 18:42:23 by gscuderi          #+#    #+#             */
/*   Updated: 2024/06/19 21:27:35 by gscuderi         ###   ########.fr       */
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
	if (n_elem && el_size && (n_elem * el_size) > UINT_MAX)
		return (NULL);
	ptr = malloc(tot);
	while (i < tot)
		((unsigned char *)ptr)[i++] = '\0';
	return (ptr);
}

size_t	ft_strlen(const char *str)
{
	int	i;
	
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	cc;

	cc = (char) c;
	i = 0;
	while (s[i])
	{
		if (s[i] == cc)
			return ((char *) &s[i]);
		i++;
	}
	if (s[i] == cc)
		return ((char *) &s[i]);
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
		i++;
		j++;
	}
	dest[i + j] = '\0';
 }