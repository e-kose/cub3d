/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekose <ekose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 14:35:47 by ekose             #+#    #+#             */
/*   Updated: 2024/09/22 14:42:10 by ekose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

size_t	ft_strlcpy2(char *dst, const char *src, size_t size)
{
	size_t	cur;

	if (size == 0)
		return (ft_strlen(src));
	cur = 0;
	while (src[cur] && cur < (size - 1))
	{
		dst[cur] = src[cur];
		cur++;
	}
	return (ft_strlen(src));
}

char	*ft_strappend(char **dest, char const *str)
{
	char	*old_dest;

	old_dest = *dest;
	*dest = ft_strjoin(*dest, str);
	free(old_dest);
	return (*dest);
}

int	ft_is_only(char *line, char c)
{
	size_t	cur;

	cur = 0;
	while (line[cur])
	{
		if (line[cur] != c && line[cur] != '\n')
			return (0);
		cur++;
	}
	return (1);
}

int	ft_is_empty(char *line)
{
	if (ft_strlen(line) == 1 && line[0] == '\n')
		return (1);
	return (0);
}

int	ft_str_contains(char *str, char c)
{
	size_t	cur;

	cur = 0;
	while (str[cur])
	{
		if (str[cur] == c)
			return (1);
		cur++;
	}
	return (0);
}
