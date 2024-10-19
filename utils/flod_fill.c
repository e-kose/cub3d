/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flod_fill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehmyilm <mehmyilm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 12:39:08 by mehmyilm          #+#    #+#             */
/*   Updated: 2024/10/19 19:07:41 by mehmyilm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	ft_fill_space(t_map *map)
{
	int	i;
	int	j;

	map->cpymap = malloc(sizeof(char) * (map->map_height + 1));
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

void	ft_flood_fill(int plyr_y, int plyr_x, t_map *map)
{
	if (plyr_y < 0 || plyr_x < 0 || plyr_y >= map->map_height
		|| plyr_x >= (int)ft_strlen(map->cpymap[plyr_y])
		|| map->cpymap[plyr_y][plyr_x] == '1')
		return ;
	map->cpymap[plyr_y][plyr_x] = '1';
	ft_flood_fill(plyr_y +1, plyr_x, map);
	ft_flood_fill(plyr_y -1, plyr_x, map);
	ft_flood_fill(plyr_y, plyr_x +1, map);
	ft_flood_fill(plyr_y, plyr_x -1, map);
}

void	ft_check_fill(t_data *data)
{
	int	i;
	int	j;
	int	re_count;

	re_count = 0;
	i = -1;
	while (data->map->cpymap[++i])
	{
		j = -1;
		while (data->map->cpymap[i][++j])
		{
			if (data->map->cpymap[i][j] == 'B')
				re_count++;
		}
	}
	if (re_count != data->map->space_count)
	{
		ft_print_double_str(data->map->cpymap);
		ft_free_double_str(data->map->cpymap);
		ft_free(data, "Map is not closed");
	}
}
