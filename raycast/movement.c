/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekose <ekose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 18:04:29 by mehmyilm          #+#    #+#             */
/*   Updated: 2024/11/03 15:18:50 by ekose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	ft_move_ws(t_data *data, int direction)
{
	double	des_x;
	double	des_y;

	des_x = data->player->loc_x + data->player->dir_x * (double)2 / 35 * direction;
	des_y = data->player->loc_y + data->player->dir_y * (double)2 / 35 * direction;
	if (data->map->map[(int)data->player->loc_y][(int)des_x] == '0')
		data->player->loc_x = des_x;
	if (data->map->map[(int)des_y][(int)data->player->loc_x] == '0')
		data->player->loc_y = des_y;
}

void	ft_move_ad(t_data *data, int direction)
{
	double	des_x;
	double	des_y;

	des_x = data->player->loc_x + data->player->plane_x
		* (double)2 / 35 * direction;
	des_y = data->player->loc_y + data->player->plane_y
		* (double)2 / 35 * direction;
	if (data->map->map[(int)data->player->loc_y][(int)des_x] == '0')
		data->player->loc_x = des_x;
	if (data->map->map[(int)des_y][(int)data->player->loc_x] == '0')
		data->player->loc_y = des_y;
}

void	ft_rotate_player(t_data *data, int direction)
{
	double	old_dirx;
	double	old_planex;
	double	rotate_angle;

	rotate_angle = 0.05 * direction;
	old_dirx = data->player->dir_x;
	data->player->dir_x = data->player->dir_x * cos(rotate_angle)
		- data->player->dir_y * sin(rotate_angle);
	data->player->dir_y = old_dirx * sin(rotate_angle)
		+ data->player->dir_y * cos(rotate_angle);
	old_planex = data->player->plane_x;
	data->player->plane_x = data->player->plane_x * cos(rotate_angle)
		- data->player->plane_y * sin(rotate_angle);
	data->player->plane_y = old_planex * sin(rotate_angle)
		+ data->player->plane_y * cos(rotate_angle);
}
