/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 12:34:37 by anboisve          #+#    #+#             */
/*   Updated: 2022/11/23 17:06:15 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_bzero(void *p, size_t size)
{
	while (size--)
		((char *)p)[size] = 0;
	return (p);
}

void	*xfree(void *p)
{
	if (p)
		free(p);
	return (NULL);
}

void	*ft_calloc(size_t size, size_t count)
{
	char	*new;

	new = malloc(size * count);
	if (!new)
		return (new = xfree(new));
	new = ft_bzero(new, size * count);
	return (new);
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *sfree, char *s2)
{
	size_t	s1_i;
	size_t	s2_i;
	char	*new;

	s1_i = ft_strlen(sfree);
	s2_i = ft_strlen(s2);
	new = ft_calloc(s1_i + s2_i + 1, sizeof(char));
	if (!new)
		return (new = xfree(new));
	while (s1_i + s2_i-- > s1_i)
		new[s1_i + s2_i] = s2[s2_i];
	while (s1_i--)
		new[s1_i] = sfree[s1_i];
	return (xfree(sfree), new);
}
