/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 13:31:55 by anboisve          #+#    #+#             */
/*   Updated: 2022/11/20 17:27:15 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *s1)
{
	int	i;

	i = 0;
	while (s1 && s1[i])
		i++;
	return (i);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*new;
	size_t	i;

	new = malloc(count * size);
	if (!new)
		return (NULL);
	i = count * size;
	while (i)
		new[--i] = 0;
	return (new);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*new;

	i = 0;
	j = 0;
	new = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (!new)
		return (NULL);
	while (s1 && s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
	{
		new[i + j] = s2[j];
		j++;
	}
	return (new);
}

char	*ft_str_dup(char *s, int *start)
{
	size_t	i;
	int		tmp;
	char	*dup;

	i = 0;
	while (s[i + *start] != 0 && s[i + *start] != '\n')
		i++;
	if (s[i + *start] == '\n')
		i++;
	dup = ft_calloc(i + 1, sizeof(char));
	if (!dup)
		return (NULL);
	tmp = ++i;
	while (i--)
		dup[i] = s[i + *start];
	*start = *start + tmp;
	return (dup);
}

char	*ft_str_dup2(char *s, int *start)
{
	size_t	i;
	int		tmp;
	char	*dup;

	i = 0;
	while (s && s[i + *start] != 0)
		i++;
	dup = ft_calloc(i + 1, sizeof(char));
	if (!dup)
		return (NULL);
	tmp = ++i;
	while (i--)
	{
		dup[i] = s[i + *start];
	}
	return (dup);
}
