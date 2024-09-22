/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekose <ekose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 00:23:00 by ekose             #+#    #+#             */
/*   Updated: 2024/09/22 14:41:52 by ekose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	init_parsed_struct(t_parsed **result)
{
	*result = malloc(sizeof(t_parsed));
	if (!(*result))
		return (0);
	(*result)->north_texture = NULL;
	(*result)->south_texture = NULL;
	(*result)->east_texture = NULL;
	(*result)->west_texture = NULL;
	(*result)->floor_color = -1;
	(*result)->ceil_color = -1;
	(*result)->map2d = malloc(sizeof(t_map2D));
	if (!((*result)->map2d))
		return (free(*result), 0);
	(*result)->map2d->map = NULL;
	(*result)->map2d->width = 0;
	(*result)->map2d->height = 0;
	(*result)->map1d = malloc(sizeof(t_map1D));
	if (!((*result)->map1d))
		return (free((*result)->map2d), free(*result), 0);
	(*result)->map1d->map = NULL;
	(*result)->map1d->width = 0;
	(*result)->map1d->height = 0;
	return (1);
}

int	has_every_data(t_parsed *map)
{
	int	count;

	count = 0;
	if (map->north_texture)
		count++;
	if (map->south_texture)
		count++;
	if (map->east_texture)
		count++;
	if (map->west_texture)
		count++;
	if (map->floor_color != -1)
		count++;
	if (map->ceil_color != -1)
		count++;
	if (count == 6)
		return (1);
	return (0);
}

int	check_map_line_char(char *line)
{
	size_t	cur;

	cur = 0;
	while (line[cur] && line[cur] != '\n')
	{
		if (!ft_str_contains(" 10NSEWP", line[cur]))
			return (0);
		cur++;
	}
	return (1);
}

int_least32_t	create_map1d(t_parsed *map)
{
	int	x;
	int	y;
	int	cur;

	map->map1d->width = map->map2d->width;
	map->map1d->height = map->map2d->height;
	map->map1d->map = malloc(sizeof(int)
			* (map->map1d->width * map->map1d->height));
	if (!map->map1d->map)
		return (0);
	y = -1;
	cur = -1;
	while (map->map2d->map[++y])
	{
		x = -1;
		while (map->map2d->map[y][++x])
		{
			map->map1d->map[++cur] = 1;
			if (map->map2d->map[y][x] == 'P')
				map->map1d->map[cur] = 2;
			else if (ft_str_contains("0NSEW", map->map2d->map[y][x]))
				map->map1d->map[cur] = 0;
		}
	}
	return (1);
}

t_parsed	*parse(char *file_path)
{
	t_parsed	*result;
	char		*map_line;

	if (!init_parsed_struct(&result))
		return (NULL);
	map_line = parse_map_file(file_path, result);
	if (!map_line)
		return (0);
	result->map2d->map = parse_map_line(map_line);
	if (!result->map2d->map)
		return (free(map_line), free(result), NULL);
	result->map2d->height = get_map_height(result->map2d->map);
	result->map2d->width = get_map_width(result->map2d->map);
	free(map_line);
	if (!check_map(result))
		return (free_parsed(result));
	if (!create_map1d(result))
		return (free_parsed(result));
	get_player(result->map2d->map, &(result->player));
	return (result);
}
