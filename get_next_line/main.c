/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 17:16:34 by anboisve          #+#    #+#             */
/*   Updated: 2022/11/23 17:27:01 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*tmp;
	char	a;

	tmp = &a;
	fd = open("test.txt", O_RDONLY);
	while (tmp != NULL)
	{
		tmp = get_next_line(fd);
		printf("%s", tmp);
		if (tmp)
			free(tmp);
	}
	close (fd);
	return (0);
}
