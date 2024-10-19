/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehmyilm <mehmyilm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 16:34:49 by mehmyilm          #+#    #+#             */
/*   Updated: 2024/10/19 19:12:18 by mehmyilm         ###   ########.fr       */
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
