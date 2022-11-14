/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 13:32:00 by anboisve          #+#    #+#             */
/*   Updated: 2022/11/14 13:21:48 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <fcntl.h>

# ifndef FD_MAX
#  define FD_MAX 256
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

typedef struct s_info
{
	char	*book[FD_MAX + 1];
	char	*new;
	int		end_line;
	int		fd;
	int		read_val;
}	t_info;

char	*get_next_line(int fd);
int		ft_strlen(char *s1);
char	*ft_str_dup(char *s1);
void	*ft_calloc(size_t count, size_t size);
void	*ft_super_free(void *p);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif // GET_NEXT_LINE_H
