/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscuderi <gscuderi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 18:42:23 by gscuderi          #+#    #+#             */
/*   Updated: 2024/06/09 18:18:44 by gscuderi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

/*ft transported from libft, clean the code*/

void	*ft_calloc(size_t n_elem, size_t el_size)
{
	void	*ptr;

	if (n_elem && el_size && (n_elem * el_size) > 4294967295)
		return (NULL);
	ptr = malloc(n_elem * el_size);
	if (ptr == NULL)
		return ((void *)ptr);
	ft_bzero(ptr, n_elem * el_size);
	return ((void *)ptr);
}

void	ft_bzero(void *ptr, size_t n)
{
	char	*tmp_ptr;
	size_t	i;

	i = 0;
	tmp_ptr = (char *) ptr;
	while (i < n)
		tmp_ptr[i++] = 0;
}

//potrebbe non tornare lunghezza con null
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

/*Crucially, the ft_strjoin 
function ensures that sufficient memory is allocated for the new buffer, 
considering both sets of data.*/

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		tot_len;
	char		*final_ptr;

	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	tot_len = ft_strlen(s1) + ft_strlen(s2);
	final_ptr = (char *)malloc((tot_len + 1) * sizeof(char));
	if (!final_ptr)
		return (NULL);
	ft_strlcpy(final_ptr, s1, ft_strlen(s1) + 1);
	ft_strlcpy(final_ptr + ft_strlen(s1), s2, ft_strlen(s2) + 1);
	final_ptr[tot_len] = '\0';
	return (final_ptr);
}

char	*ft_strdup(const char *str)
{
	char	*dup_str;
	size_t	i;

	if (!str)
		return (NULL);
	dup_str = (char *)malloc(ft_strlen(str) * sizeof(char));
	if (!dup_str)
		return (NULL);
	i = 0;
	while (str[i])
	{
		dup_str[i] = str[i];
		i++;
	}
	dup_str[i] = '\0';
	return (dup_str);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(src);
	if (n == 0)
		return (len);
	while (src[i] && i < n - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (len);
}