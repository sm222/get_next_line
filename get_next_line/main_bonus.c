/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:18:40 by anboisve          #+#    #+#             */
/*   Updated: 2022/11/23 17:34:35 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

#define RED    "\x1B[31m"
#define GRN    "\x1B[32m"
#define YEL    "\x1B[33m"
#define BLU    "\x1B[34m"
#define MAG    "\x1B[35m"
#define CYN    "\x1B[36m"
#define WHT    "\x1B[37m"
#define RESET  "\x1B[0m"
#define CLE    "\e[1;1H\e[2J"

/*

//void	*xfree(void *p)
//{
//	if (p)
//		free(p);
//	return (NULL);
//}

int	main(void)
{
	int		fd[3];
	char	*tmp[4];
	int		i;

	i = 0;
	fd[0] = open("test.txt", O_RDONLY);
	fd[1] = open("test1.txt", O_RDONLY);
	fd[2] = open("test2.txt", O_RDONLY);
	LOOP: tmp[0] = get_next_line(fd[0]);
	tmp[1] = get_next_line(fd[1]);
	tmp[2] = get_next_line(fd[2]);
	if (tmp[0])
		printf(BLU"[fd-1]"WHT" = %s", tmp[0]);
	xfree(tmp[0]);
	if (tmp[1])
		printf(RED"[fd-2]"WHT" = %s", tmp[1]);
	xfree(tmp[1]);
	if (tmp[2])
		printf(GRN"[fd-3]"WHT" = %s", tmp[2]);
	xfree(tmp[2]);
	printf("\ntime call -- %d\n", ++i);
	if (tmp[0] != NULL || tmp[1] != NULL || tmp[2] != NULL)
		goto LOOP;
	close(fd[0]);
	close(fd[1]);
	close(fd[2]);
}
*/
