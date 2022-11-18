/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 13:30:18 by anboisve          #+#    #+#             */
/*   Updated: 2022/11/17 17:31:01 by anboisve         ###   ########.fr       */
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
	while (s[++i])
		if (s[i] == '\n')
			return (i);
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

char	*chup(char *page)
{
	size_t	i;

	i = 0;
}

char	*get_next_line(int fd)
{
	t_info		t_info;
	static char	*book[100];

	t_info.new = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	t_info.fd = fd;
	if (!book[fd])
		book[fd] = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	t_info.read_val = read(fd, t_info.new, BUFFER_SIZE);
	t_info.re_val = ft_strjoin(book[fd], t_info.new);
	book[fd] = t_info.re_val;
	return (t_info.re_val);
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
