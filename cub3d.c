/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekose <ekose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:56:03 by ekose             #+#    #+#             */
/*   Updated: 2024/11/03 14:07:10 by ekose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/cub3d.h"

static void	ft_init_value(t_data *data)
{
	int	i;

	i = -1;
	data->map->_1d_map = ft_strdup("\n");
	data->map->map = NULL;
	data->node = NULL;
	while (++i < 6)
		data->texture->txt_count[i] = 0;
	data->map->map_width = 0;
	data->map->map_height = 0;
	data->map->cpymap = NULL;
	data->texture->north = NULL;
	data->texture->south = NULL;
	data->texture->west = NULL;
	data->texture->east = NULL;
	data->texture->floor = NULL;
	data->texture->ceiling = NULL;
	data->mlx = NULL;
	data->key->w = 0;
	data->key->a = 0;
	data->key->s = 0;
	data->key->d = 0;
	data->key->left = 0;
	data->key->right = 0;
	data->raycast->hit = 0;
}
static void	ft_init(t_data *data)
{
	data->map = malloc(sizeof(t_map));
	data->texture = malloc(sizeof(t_texture));
	data->player = malloc(sizeof(t_player));
	data->key = malloc(sizeof(t_key));
	data->raycast = malloc(sizeof(t_raycast));
	if (data->map == NULL || data->texture == NULL
		|| data->player == NULL || data->key == NULL
		|| data->raycast == NULL)
		ft_error_msg("Malloc error");
	ft_init_value(data);
}

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac != 2)
		ft_error_msg("Number of invalid arguments");
	data = malloc(sizeof(t_data));
	if(data == NULL)
		ft_error_msg("Malloc error");
	ft_init(data);
	ft_parse_map(av[1], data);
	// printf("NO: %s\n", data->texture->north);
	// printf("SO: %s\n", data->texture->south);
	// printf("WE: %s\n", data->texture->west);
	// printf("EA: %s\n", data->texture->east);
	// printf("F: %d,%d,%d\n", data->texture->floor_color[0], data->texture->floor_color[1], data->texture->floor_color[2]);
	// printf("C: %d,%d,%d\n", data->texture->ceiling_color[0], data->texture->ceiling_color[1], data->texture->ceiling_color[2]);
	// printf("Map:\n");
	// ft_print_double_str(data->map->map);
	// printf("copymap:\n");
	// ft_print_double_str(data->map->cpymap);
	ft_print_double_str(data->map->map);
	printf("player_dir: %c\n", data->player_dir);
	ft_init_mlx(data);
	ft_free(data, NULL);
	return (0);
}
