/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehmyilm <mehmyilm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 16:34:49 by mehmyilm          #+#    #+#             */
/*   Updated: 2024/10/21 13:42:08 by mehmyilm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	ft_check_wall(t_data *data, char **map)
{
	int		i;
	int		j;

	i = -1;
	//ilk satır ve son satırda 0 olmamalı
	if (ft_strchr(map[0], '0')
		|| ft_strchr(map[data->map->map_height -1], '0'))
		ft_free(data, "Map must be surrounded by walls");
	while (map[++i])
	{
		// mapin sağı solu boşluk  ve 1 den farklı bir karakter olmamalı.
		j = -1;
		if ((map[i][0] != '1' && map[i][0] != ' ')
			|| (map[i][ft_strlen(map[i]) - 1] != '1'
			&& map[i][ft_strlen(map[i]) - 1] != ' '))
			ft_free(data, "Map must be surrounded by walls");
		while (map[i][++j])
		{
			// 0 ın aşağısı yukarısı boş olamaz
			if (map[i][j] == '0'
				&& ((i +1 < data->map->map_height
				&& (!map[i +1][j] || j > (int)ft_strlen(map[i +1])))
				|| (i -1 >= 0 && (!map[i - 1][j]
				|| j > (int)ft_strlen(map[i - 1])))))
				ft_free(data, "Map must be surrounded by walls");
		}
	}
}

void	ft_check_char(t_data *data, char *line)
{
	int			i;
	int			check;
	char		*tmp;

	check = 0;
	i = 0;
	tmp = ft_strtrim(line, "\n");
	if (data->map->map_width < (int) ft_strlen(line))
		data->map->map_width = (int) ft_strlen(line);
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
void	ft_check_line(t_data *data)
{
	t_list	*tmp;
	char	*line;

	tmp = data->node;
	while (tmp)
	{
		line = (char *)tmp->content;
		if (ft_strlen(line) == 1 && line[0] == '\n')
		{
			tmp = tmp->next;
			while (tmp)
			{
				line = (char *)tmp->content;
				if (ft_strlen(line) != 1 && line[0] != '\n')
					ft_free(data, "Invalid map");
				tmp = tmp->next;
			}
		}
		if (tmp)
			tmp = tmp->next;
	}
}
