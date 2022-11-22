/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 13:30:18 by anboisve          #+#    #+#             */
/*   Updated: 2022/11/22 17:31:22 by anboisve         ###   ########.fr       */
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
		return (NULL);
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
	static char	*book;
	t_info		t_info;

	if (!book)
		book = ft_calloc(1, sizeof(char));
	t_info.rv = BUFFER_SIZE;
	t_info.tmp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	while (t_info.rv > 0 && ft_find(book) == '0')
	{
		t_info.tmp = ft_bzero(t_info.tmp, BUFFER_SIZE + 1);
		t_info.rv = read(fd, t_info.tmp, BUFFER_SIZE);
		if (t_info.rv <= 0)
			break ;
		book = ft_strjoin(book, t_info.tmp);
	}
	t_info.tmp = xfree(t_info.tmp);
	if (t_info.rv == -1)
		return (book = xfree(book));
	if (t_info.rv <= 0 && *book == 0)
		return (book = xfree(book));
	t_info.tmp = ft_tiny_split(book, &t_info.cut);
	t_info.tmp2 = book;
	book = ft_strjoin(NULL, book + t_info.cut);
	return (t_info.tmp2 = xfree(t_info.tmp2), t_info.tmp);
}

int	main(void)
{
	int	fd;

	fd = open("test.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	close (fd);
	return (0);
}

/*
tmp = buffer
buffer = str_joi(buffer, other)
free(tmp)
*/