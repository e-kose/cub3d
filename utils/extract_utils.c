/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekose <ekose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 03:40:43 by ekose             #+#    #+#             */
/*   Updated: 2024/09/22 14:42:02 by ekose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	pass_spaces(char *line, size_t cur)
{
	while (line[cur] == ' ')
		cur++;
	return (cur);
}

int	line_value_size(char *line, size_t cur)
{
	size_t	size;

	size = 0;
	while (line[cur + size] != '\n')
	{
		size++;
		if (ft_is_only(line + cur + size, ' ') && line[cur + size + 1] != '\n')
			return (size);
	}
	return (size);
}

char	*get_line_value(int prefix_len, char *line)
{
	size_t	cur;

	cur = pass_spaces(line, prefix_len);
	return (ft_substr(line, cur, line_value_size(line, cur)));
}
