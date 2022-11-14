/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 13:30:18 by anboisve          #+#    #+#             */
/*   Updated: 2022/11/14 18:57:22 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
char	*get_next_line(int fd)
{
	char	*buff;
	int		tmp[2];
	int		size;
	int		size_b;
	char	*new;

	if (fd < 0 || fd > FD_MAX || BUFFER_SIZE < 0)
		return (NULL);
	tmp[1] = 0;
	size_b = 0;
	size = -1;
	buff = ft_calloc(BUFFER_SIZE + 2, sizeof(char));
	while (tmp[1] >= 0 && size_b++ < BUFFER_SIZE)
	{
		tmp[1] = read(fd, tmp, 1);
		if (tmp[1] <= 0)
			return (ft_super_free(buff));
		buff[++size] = (char)tmp[0];
		if (tmp[0] == '\n' || tmp[1] <= 0)
			break ;
	}
	new = ft_str_dup(buff);
	free(buff);
	return (new);
}
*/

/*
char	*get_next_line(int fd)
{
	char	*buff;
	char	tmp[1];
	char	*new;
	int		read_v;
	int		i;

	i = 0;
	read_v = 1;
	if (fd < 0 || fd > FD_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	buff = ft_calloc(BUFFER_SIZE + 2, sizeof(char));
	while (read_v > 0 && i < BUFFER_SIZE)
	{
		read_v = read(fd, tmp, BUFFER_SIZE);
		buff[i] = tmp[0];
		if (tmp[0] == '\n')
			break ;
	}
	new = ft_str_dup0(tmp);
	free(buff);
	return (new);
}
*/

/*
int	main(void)
{
	int		fd;
	char	*p;

	fd = open("test.txt", O_RDWR);
	p = get_next_line(fd);
	printf("%s", p);
		p = get_next_line(fd);
	printf("%s", p);
		p = get_next_line(fd);
	printf("%s", p);
		p = get_next_line(fd);
	printf("%s", p);
	free(p);
	close(fd);
	return (0);
}
*/

void	ft_str_cpy(char *dst, char *src)
{
	int	i;

	i = -1;
	while (src[++i])
		dst[i] = src[i];
}

void	ft_create_page(t_info *data, char **book)
{
	book[data->fd] = data->new;
}

char	*get_next_line(int fd)
{
	t_info		t_info;
	static char	*book[FD_MAX + 1];

	t_info.fd = fd;
	t_info.new = "test";
	t_info.end_line = 0; // end of the line for the book
	if (!book[fd])
		ft_create_page(&t_info, book);
	else
		printf("%s", book[fd]);
	return (NULL);
}

int	main(void)
{
	get_next_line(1);
	get_next_line(0);
	get_next_line(1);
	return (0);
}
