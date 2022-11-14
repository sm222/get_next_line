/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 13:31:55 by anboisve          #+#    #+#             */
/*   Updated: 2022/11/14 12:52:21 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s1)
{
	int	i;

	i = 0;
	while (s1 && s1[i])
		i++;
	return (i);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*tmp;
	int		tmp_size;

	tmp = malloc(count * size);
	if (!tmp)
		return (NULL);
	tmp_size = count * size;
	while (tmp_size >= 0)
		tmp[tmp_size--] = 0;
	return (tmp);
}

char	*ft_str_dup(char *s1)
{
	int		i;
	int		size;
	char	*new;

	size = ft_strlen(s1);
	new = ft_calloc(size + 1, sizeof(char));
	if (!new)
		return (NULL);
	i = -1;
	while (s1[++i])
		new[i] = s1[i];
	return (new);
}

void	*ft_super_free(void *p)
{
	if (p)
		free(p);
	return (NULL);
}

/*
char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*r;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	if (start < ft_strlen(s))
		while (s[i + start] && len > i)
			i++;
	r = ft_calloc(i * sizeof(char) + 1, 1);
	if (!r)
		return (NULL);
	if (start >= ft_strlen(s))
		return (r);
	ft_strlcpy(r, &s[start], i + 1);
	return (r);
}
*/
