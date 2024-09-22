/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcheck.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekose <ekose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 01:24:06 by ekose             #+#    #+#             */
/*   Updated: 2024/09/22 15:02:55 by ekose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	count_correct_sides(t_map2D *map2d, size_t x, size_t y)
{
	int	correct_sides;

	correct_sides = 4;
	if (x - 1 >= map2d->width)
		correct_sides--;
	else
		correct_sides -= can_exit_map_from_pos(map2d, x - 1, y);
	if (x + 1 >= map2d->width)
		correct_sides--;
	else
		correct_sides -= can_exit_map_from_pos(map2d, x + 1, y);
	if (y - 1 >= map2d->height)
		correct_sides--;
	else
		correct_sides -= can_exit_map_from_pos(map2d, x, y - 1);
	if (y + 1 >= map2d->height)
		correct_sides--;
	else
		correct_sides -= can_exit_map_from_pos(map2d, x, y + 1);
	return (correct_sides);
}

int	can_exit_map_from_pos(t_map2D *map2d, size_t x, size_t y)
{
	int	correct_sides;

	if (map2d->map[y][x] == '.' || map2d->map[y][x] == '1')
		return (0);
	else if (map2d->map[y][x] == '0' || map2d->map[y][x] == 'P')
		map2d->map[y][x] = '.';
	else if (map2d->map[y][x] == ' ')
		return (1);
	correct_sides = count_correct_sides(map2d, x, y);
	return (correct_sides != 4);
}

int	check_map(t_parsed *map)
{
	t_player	player;
	t_map2D		*map2d_dup;
	int			players_count;

	players_count = get_player(map->map2d->map, &player);
	if (players_count == 0)
	{
		printf("Error\n(Map doesn't contain a position for the player)\n");
		return (0);
	}
	else if (players_count != 1)
	{
		printf("Error\n(Map contains multiple positions for the player)\n");
		return (0);
	}
	map2d_dup = dup_map2d(map->map2d);
	if (!map2d_dup)
		return (0);
	if (can_exit_map_from_pos(map2d_dup, player.x, player.y))
	{
		printf("Error\n(Map is not closed)\n");
		return (free_map2d(map2d_dup), 0);
	}
	return (free_map2d(map2d_dup), 1);
}
