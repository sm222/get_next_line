/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 13:30:18 by anboisve          #+#    #+#             */
/*   Updated: 2024/05/21 18:50:14 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_tiny_split(char *s, size_t *cut)
{
	char	*new;
	size_t	i;

	i = 0;
	while (s[i])
		if (s[i++] == '\n')
			break ;
	new = ft_calloc(i + 1, sizeof(char));
	if (!new)
		return (new = ft_sfree(new));
	*cut = i;
	while (i--)
		new[i] = s[i];
	return (new);
}

char	ft_find(char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i])
	{
		if (s[i] == '\n')
			return ('\n');
		i++;
	}
	return ('0');
}

char	*safe_return(char **book, t_info *t_val)
{
	t_val->tmp = ft_tiny_split(*book, &t_val->cut);
	if (!t_val->tmp)
	{
		*book = ft_sfree(*book);
		return (NULL);
	}
	t_val->tmp2 = *book;
	*book = ft_strjoin(NULL, *book + t_val->cut);
	t_val->tmp2 = ft_sfree(t_val->tmp2);
	return (t_val->tmp);
}

char	*get_next_line(int fd)
{
	static char	*book = NULL;
	t_info		t_val;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (book = ft_sfree(book));
	if (!book)
		book = ft_calloc(1, sizeof(char));
	if (!book)
		return (NULL);
	while (ft_find(book) == '0')
	{
		ft_bzero(t_val.readtmp, BUFFER_SIZE + 1);
		t_val.rv = read(fd, t_val.readtmp, BUFFER_SIZE);
		if (t_val.rv <= 0)
			break ;
		book = ft_strjoin(book, t_val.readtmp);
		if (!book)
			return (NULL);
	}
	if (t_val.rv == -1 || (t_val.rv <= 0 && *book == 0))
	{
		book = ft_sfree(book);
		return (NULL);
	}
	return (safe_return(&book, &t_val));
}
