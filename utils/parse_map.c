/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehmyilm <mehmyilm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:39:49 by ekose             #+#    #+#             */
/*   Updated: 2024/10/30 18:46:45 by mehmyilm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	ft_init_player_pos(t_data *data)
{
	if (data->player_dir == 'W')
	{
		data->player->dir_x = -1;
		data->player->dir_y = 0;
		data->player->plane_x = 0;
		data->player->plane_y = -0.66;
	}
	else if (data->player_dir == 'E')
	{
		data->player->dir_x = 1;
		data->player->dir_y = 0;
		data->player->plane_x = 0;
		data->player->plane_y = 0.66;
	}
}

void	ft_init_player(t_data *data)
{
	if (data->player_dir == 'N')
	{
		data->player->dir_x = 0;
		data->player->dir_y = -1;
		data->player->plane_x = 0.66;
		data->player->plane_y = 0;
	}
	else if (data->player_dir == 'S')
	{
		data->player->dir_x = 0;
		data->player->dir_y = 1;
		data->player->plane_x = -0.66;
		data->player->plane_y = 0;
	}
	ft_init_player_pos(data);
}
void	ft_parse_map(char *av, t_data *data)
{
	size_t		i;
	int			fd;

	data->argv = av;
	i = ft_strlen(data->argv) - 4;
	if (ft_strncmp(&(data->argv[i]), ".cub", 4) != 0 && i != 0)
		ft_free(data, "Invalid file extension");
	fd = open(data->argv, O_RDONLY, 777);
	if (fd == -1)
		ft_free(data, "File not found");
	ft_read_map(data);
	ft_check_wall(data, data->map->map);
	ft_fill_space(data->map);
	ft_flood_fill(data->plyr_loc[0], data->plyr_loc[1], data->map);
	ft_check_fill(data, -1, -1);
	ft_check_texture(data);
	ft_check_space(data);
	data->texture->floor = ft_clean_rgb(data, data->texture->floor);
	data->texture->ceiling = ft_clean_rgb(data, data->texture->ceiling);
	ft_convert_rgb(data, data->texture->floor, 'F');
	ft_convert_rgb(data, data->texture->ceiling, 'C');
	ft_init_player(data);
}
