/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehmyilm <mehmyilm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:20:46 by ekose             #+#    #+#             */
/*   Updated: 2024/10/19 13:10:05 by mehmyilm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"
void	ft_print_double_str(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		printf("str[%d]: %s\n",i,str[i]);
}
int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (-1);
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

void	ft_check_line(t_data *data, char *line)
{
	int			i;
	int			check;
	char		*tmp;

	check = 0;
	i = 0;
	tmp = ft_strtrim(line, "\n");
	if (data->map->map_width < (int) ft_strlen(line))
		data->map->map_width = ft_strlen(line);
	while (tmp[i] && (tmp[i] == ' '))
		i++;
	while (tmp[i])
	{
		if (tmp[i] != 'N' && tmp[i] != 'S' && tmp[i] != 'E' && tmp[i] != 'W'
			&& tmp[i] != '0' && tmp[i] != '1' && tmp[i] != ' ' && tmp[i] != '\n')
			check++;
		i++;
	}
	free(tmp);
	if (check > 0)
		ft_free(data, "Invalid map character");
}
