/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flod_fill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekose <ekose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 12:39:08 by mehmyilm          #+#    #+#             */
/*   Updated: 2024/11/03 14:04:04 by ekose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	ft_fill_space(t_data *data)
{
	int		i;
	int		j;
	t_map	*map;

	map = data->map;
	map->cpymap = malloc(sizeof(char *) * (map->map_height + 1));
	if (!map->cpymap)
		ft_error_msg("Malloc eror");
	map->cpymap[map->map_height] = NULL;
	map->space_count = 0;
	i = -1;
	while (map->map[++i])
	{
		j = -1;
		while (map->map[i][++j])
		{
			if (map->map[i][j] == ' ')
			{
				map->space_count++;
				map->map[i][j] = 'B';
			}
		}
		map->cpymap[i] = ft_strdup(map->map[i]);
	}
}
void	ft_check_space(t_data *data)
{
	char	**map;
	int		i;
	int		j;

	map = data->map->map;
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if ((map[i][j] == '0' || map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'E' || map[i][j] == 'W')
				&& ((i -1 >= 0 && map[i -1][j] == 'B')
				|| (i +1 < data->map->map_height && map[i +1][j] == 'B')
				|| (j -1 >= 0 && map[i][j -1] == 'B')
				|| (j +1 < (int)ft_strlen(map[i]) && map[i][j +1] == 'B')))
				ft_free(data, "Map has empty space");
		}
	}
}
void	ft_flood_fill(int plyr_y, int plyr_x, t_map *map)
{
	if (plyr_y < 0 || plyr_x < 0 || plyr_y >= map->map_height
		|| plyr_x >= (int)ft_strlen(map->cpymap[plyr_y])
		|| map->cpymap[plyr_y][plyr_x] == 'B' || map->cpymap[plyr_y][plyr_x] == 'X')
		return ;
	map->cpymap[plyr_y][plyr_x] = 'X';
	ft_flood_fill(plyr_y +1, plyr_x, map);
	ft_flood_fill(plyr_y -1, plyr_x, map);
	ft_flood_fill(plyr_y, plyr_x +1, map);
	ft_flood_fill(plyr_y, plyr_x -1, map);
}

void	ft_check_fill(t_data *data, int i, int j)
{
	char	**map;

	map = data->map->cpymap;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] != 'X' && map[i][j] != 'B')
			{
				if (map[i][j] == '1'
					&& ((i -1 >= 0
					&& (map[i -1][j] != 'B' && map[i -1][j] != '1'))
					|| (i +1 < data->map->map_height
					&& (map[i +1][j] != 'B' && map[i +1][j] != '1'))
					|| (j -1 >= 0 && (map[i][j -1] != 'B'
					&& map[i][j -1] != '1')) || (j +1 < (int)ft_strlen(map[i])
					&& (map[i][j +1] != 'B' && map[i][j +1] != '1'))))
					ft_free(data, "Multiple map error");
			}
		}
	}
}
