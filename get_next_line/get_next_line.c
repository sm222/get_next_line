/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 13:30:18 by anboisve          #+#    #+#             */
/*   Updated: 2022/11/18 17:41:31 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*xfree(void *p)
{
	if (p)
		free(p);
	return (NULL);
}

int	ft_find_line(char *s)
{
	int	i;

	i = -1;
	if (!s)
		return (-1);
	while (s[++i])
		if (s[i] == '\n')
			return (i + 1);
	return (-1);
}

char	*ft_str_cpy(char *dst, char *src)
{
	int	i;
	int	j;

	j = ft_find_line(src);
	i = 0;
	while (i <= j)
	{
		dst[i] = src[i];
		i++;
	}
	return (dst);
}

char	*get_next_line(int fd)
{
	static char	*book;
	int			br;
	char		*tmp;
	char		*ffree;
	int			line;

	br = BUFFER_SIZE;
	tmp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	while (br == BUFFER_SIZE && ft_find_line(book) == -1)
	{
		br = read(fd, tmp, BUFFER_SIZE);
		ffree = book;
		book = ft_strjoin(book, tmp);
		xfree(ffree);
	}
	xfree(tmp);
	if (br <= 0)
		return (NULL);
	line = ft_find_line(book);
	tmp = ft_str_dup(book, line);
	if (line == -1)
		return (tmp);
	ffree = book;
	book = ft_str_dup(book, ft_strlen(book + line));
	xfree(ffree);
	return (tmp);
}

int	main(void)
{
	int	fd;

	fd = open("test.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
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