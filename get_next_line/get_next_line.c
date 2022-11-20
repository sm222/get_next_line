/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 13:30:18 by anboisve          #+#    #+#             */
/*   Updated: 2022/11/20 17:49:52 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*xfree(void *p)
{
	if (p)
		free(p);
	return (NULL);
}

int	ft_strchr(char c, char *filter)
{
	int	i;

	i = -1;
	while (filter && filter[++i])
		if (filter[i] == c)
			return (i);
	return (-1);
}

char	*get_next_line(int fd)
{
	static char	*book;
	char		*tmp;
	char		*swap;
	int			i;
	int			vread;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	i = 0;
	tmp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!tmp)
		return (NULL);
	vread = 1;
	while (ft_strchr('\n', book) == -1 && vread)
	{
		vread = read(fd, tmp, BUFFER_SIZE);
		if (vread < 0)
			return (xfree(tmp), xfree(book), NULL);
		swap = book;
		book = ft_strjoin(book, tmp);
		xfree(swap);
	}
	xfree(tmp);
	if (book[0] == 0)
		return (xfree(book));
	tmp = ft_str_dup(book, &i);
	swap = book;
	book = ft_str_dup2(book, &i);
	xfree(swap);
	return (tmp);
}

/*
int	main(void)
{
	int	fd;

	fd = open("test.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	close (fd);
	return (0);
}
*/


/*
tmp = buffer
buffer = str_joi(buffer, other)
free(tmp)
*/