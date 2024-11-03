/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekose <ekose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 15:36:42 by mehmyilm          #+#    #+#             */
/*   Updated: 2024/11/03 15:11:02 by ekose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	ft_map_line(t_data *data, int x)
{
	double	step;
	double	tex_pos;
	int		i;
	int		tex_y;
	int		color;

	step = 1.0 * 64 / data->raycast->height;
	tex_pos = (data->raycast->start_y - HEIGHT \
				/ 2 + data->raycast->height / 2) * step;
	i = data->raycast->start_y;
	while (i <= data->raycast->end_y)
	{
		tex_y = (int)tex_pos & 63;
		tex_pos += step;
		color = data->img[data->raycast->side1]->addr[(64 * tex_y) \
			+ data->raycast->tex_x];
		data->mlx->addr[i * WIDTH + x] = color;
		i++;
	}
}

double	ft_calc_dis(t_data *data)
{
	if (data->raycast->side1 == 0 || data->raycast->side1 == 1)
	{
		data->raycast->perp_dist = (data->player->loc_ipx - data->player->loc_x \
		+ (1 - data->raycast->step_x) / 2) / data->raycast->raydir_x;
		if (data->raycast->perp_dist <= 0.000001)
			data->raycast->perp_dist = 0.00001;
		return (data->player->loc_y + data->raycast->perp_dist \
				* data->raycast->raydir_y);
	}
	data->raycast->perp_dist = (data->player->loc_ipy - data->player->loc_y \
		+ (1 - data->raycast->step_y) / 2) / data->raycast->raydir_y;
	if (data->raycast->perp_dist <= 0.000001)
		data->raycast->perp_dist = 0.00001;
	return (data->player->loc_x + data->raycast->perp_dist \
			* data->raycast->raydir_x);
}

void	ft_calc_wall(t_data *data)
{
	double	wall_x;

	wall_x = ft_calc_dis(data);
	wall_x -= floor(wall_x);
	data->raycast->height = (HEIGHT / data->raycast->perp_dist);
	data->raycast->tex_x = (int)(wall_x * (double)64);
	if (data->raycast->side1 == 0 || data->raycast->side1 == 1)
		data->raycast->tex_x = 64 - data->raycast->tex_x - 1;
	else if (data->raycast->side1 == 2 || data->raycast->side1 == 3)
		data->raycast->tex_x = 64 - data->raycast->tex_x - 1;
	data->raycast->start_y = -data->raycast->height / 2 + HEIGHT / 2;
	if (data->raycast->start_y < 0)
		data->raycast->start_y = 0;
	data->raycast->end_y = data->raycast->height / 2 + HEIGHT / 2;
	if (data->raycast->end_y >= HEIGHT)
		data->raycast->end_y = HEIGHT - 1;
}

void	ft_dda(t_data *data)
{
	while (data->raycast->hit == 0)
	{
		if (data->raycast->sidedist_x < data->raycast->sidedist_y)
		{
			data->raycast->sidedist_x += data->raycast->deltadist_x;
			data->player->loc_ipx += data->raycast->step_x;
			if (data->raycast->step_x == 1)
				data->raycast->side1 = 1;
			else
				data->raycast->side1 = 0;
		}
		else
		{
			data->raycast->sidedist_y += data->raycast->deltadist_y;
			data->player->loc_ipy += data->raycast->step_y;
			if (data->raycast->step_y == 1)
				data->raycast->side1 = 2;
			else
				data->raycast->side1 = 3;
		}
		if (data->map->map[data->player->loc_ipy][data->player->loc_ipx] == '1')
			data->raycast->hit = 1;
	}
}
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
	int		i;
	t_data	*data;

	data = (t_data *)param;
	// printf("loc_x: %d, hit: %d\n", data->raycast->step_x, data->raycast->step_y);
	i = 0;
	ft_put_floor_ceiling(data);
	ft_player_move(data);//roteta bakk
	while (i < WIDTH)
	{
		ft_init_raycast(data, i);
		ft_calc_side(data);
		ft_dda(data);
		ft_calc_wall(data);
		ft_map_line(data, i);
		i++;
	}
	mlx_put_image_to_window(data->mlx->mlx_ptr, data->mlx->win,
		data->mlx->img, 0, 0);
	return (0);
}
