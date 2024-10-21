/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehmyilm <mehmyilm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:39:49 by ekose             #+#    #+#             */
/*   Updated: 2024/10/21 13:16:38 by mehmyilm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

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
	ft_flood_fill(data->player[0], data->player[1], data->map);
	ft_check_fill(data);
	// ft_check_texture(data);
	data->texture->floor = ft_clean_rgb(data, data->texture->floor);
	data->texture->ceiling = ft_clean_rgb(data, data->texture->ceiling);
	ft_convert_rgb(data, data->texture->floor, 'F');
	ft_convert_rgb(data, data->texture->ceiling, 'C');

}
