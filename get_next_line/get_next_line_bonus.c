/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 12:31:43 by anboisve          #+#    #+#             */
/*   Updated: 2022/12/07 09:47:24 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_tiny_split(char *s, size_t *cut)
{
	char	*new;
	size_t	i;

	i = 0;
	while (s[i])
		if (s[i++] == '\n')
			break ;
	new = ft_calloc(1 + i, sizeof(char));
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
	while (s[i])
	{
		if (s[i] == '\n')
			return ('\n');
		i++;
	}
	return ('0');
}

char	*get_next_line(int fd)
{
	static char	*book[OPEN_MAX];
	t_info		t_val;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (NULL);
	if (!book[fd])
		book[fd] = ft_calloc(1, sizeof(char));
	t_val.tmp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	while (ft_find(book[fd]) == '0')
	{
		ft_bzero(t_val.tmp, BUFFER_SIZE + 1);
		t_val.rv = read(fd, t_val.tmp, BUFFER_SIZE);
		if (t_val.rv <= 0)
			break ;
		book[fd] = ft_strjoin(book[fd], t_val.tmp);
	}
	t_val.tmp = ft_sfree(t_val.tmp);
	if (t_val.rv == -1 || (t_val.rv <= 0 && *book[fd] == 0))
		return (book[fd] = ft_sfree(book[fd]), NULL);
	t_val.tmp = ft_tiny_split(book[fd], &t_val.cut);
	t_val.tmp2 = book[fd];
	book[fd] = ft_strjoin(NULL, book[fd] + t_val.cut);
	return (ft_sfree(t_val.tmp2), t_val.tmp);
}
