/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 13:30:18 by anboisve          #+#    #+#             */
/*   Updated: 2022/11/14 13:34:10 by anboisve         ###   ########.fr       */
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

char	*ft_create_page(t_info *data)
{
	int	i;

	i = 0;
	while (i < BUFFER_SIZE)
		i++;
	data->book[]
}

char	*get_next_line(int fd)
{
	static t_info	t_info;
	char			*new_str;

	t_info.fd = fd;
	t_info.read_val = read(fd, t_info.new, BUFFER_SIZE);
	if (!t_info.book[fd])
		
	return (NULL);
}

int	main(void)
{
	get_next_line(1);
	get_next_line(1);
	return (0);
}