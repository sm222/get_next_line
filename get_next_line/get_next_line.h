/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 13:32:00 by anboisve          #+#    #+#             */
/*   Updated: 2022/11/22 22:42:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef FD_MAX
#  define FD_MAX 256
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

typedef struct s_info
{
	char	*tmp;
	char	*tmp2;
	int		rv;
	size_t	cut;
}	t_info;

void	*xfree(void *p);
void	*ft_calloc(size_t size, size_t count);
char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
void	*ft_bzero(void *p, size_t size);

#endif // GET_NEXT_LINE_H
