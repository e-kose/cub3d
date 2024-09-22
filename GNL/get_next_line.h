/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekose <ekose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 14:57:53 by ekose             #+#    #+#             */
/*   Updated: 2024/09/22 15:11:05 by ekose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../libft/libft.h"
# define GNL_CLEAR 1
# define GNL_KEEP 0
# define BUFFER_SIZE 10000

typedef struct s_prev_list
{
	char				*prev;
	int					fd;
	struct s_prev_list	*next;
}	t_prev_list;

long	charchr(const char *s, char c);
char	*gnl_strjoin(char *s1, char const *s2);
char	*gnl_substr(char const *s, unsigned int start, size_t len);
void	shiftstr(char **str, size_t start);
char	*get_next_line(int fd, int clear);
#endif
