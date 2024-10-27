/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehmyilm <mehmyilm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 15:36:42 by mehmyilm          #+#    #+#             */
/*   Updated: 2024/10/27 17:30:53 by mehmyilm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	ft_put_floor_ceiling(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < HEIGHT / 2)
	{
		j = 0;
		while (j < WIDTH)
		{
			data->mlx->addr[i * WIDTH + j] = data->texture->ceiling_color;
			j++;
		}
		i++;
	}
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			data->mlx->addr[i * WIDTH + j] = data->texture->floor_color;
			j++;
		}
		i++;
	}
}

int	ft_game_handler(void *param)
{
	int		x;
	t_data	*data;

	data = (t_data *)param;
	x = 0;
	ft_put_floor_ceiling(data);
	player_game(data);
	// while (x < WIDTH)
	// {
	// 	calc_ray(data, x);
	// 	dda(data);
	// 	calc_wall(data);
	// 	map_line(data, x);
	// 	x++;
	// }
	// mlx_put_image_to_window(data->mlx->mlx, data->mlx->win,
	// 	data->mlx->img, 0, 0);
	return (0);
}
