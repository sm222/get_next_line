/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 12:32:44 by anboisve          #+#    #+#             */
/*   Updated: 2022/12/06 11:47:26 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

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

void	*ft_sfree(void *p);
void	*ft_calloc(size_t size, size_t count);
char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
void	*ft_bzero(void *p, size_t size);

#endif // GET_NEXT_LINE_BONUS_H
