/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehmyilm <mehmyilm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 18:41:35 by mehmyilm          #+#    #+#             */
/*   Updated: 2024/11/02 17:43:33 by mehmyilm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	ft_init_raycast(t_data *data, int x)
{
	data->raycast->camera_x = 2 * x / (double)WIDTH - 1;
	// pikselin kordinatlarını hesaplıyoruz
	data->raycast->raydir_x = data->player->dir_x
		+ data->player->plane_x * data->raycast->camera_x;
	data->raycast->raydir_y = data->player->dir_y
		+ data->player->plane_y * data->raycast->camera_x;
	// printf("loc_x: %f, loc_y: %f\n", data->player->loc_x, data->player->loc_y);
	data->player->loc_ipx = (int)data->player->loc_x;
	data->player->loc_ipy = (int)data->player->loc_y;
	data->raycast->deltadist_x = fabs(1 / data->raycast->raydir_x);
	data->raycast->deltadist_y = fabs(1 / data->raycast->raydir_y);
	//hesaplanan raydir_x ve raydir_y nin hangi yöne gideceğini belirliyoruz. yani
	// yani playerden o piksele hangi açıyla ışının nasıl gideceğini hesaplıyoruz
	data->raycast->hit = 0;
}

void	ft_calc_side(t_data *data)
{
	if (data->raycast->raydir_x < 0)
	{
		data->raycast->step_x = -1;
		data->raycast->sidedist_x = (data->player->loc_x - data->player->loc_ipx) \
			* data->raycast->deltadist_x;
	}
	else
	{
		data->raycast->step_x = 1;
		data->raycast->sidedist_x = (data->player->loc_ipx + 1.0 - data->player->loc_x) \
			* data->raycast->deltadist_x;
	}
	if (data->raycast->raydir_y < 0)
	{
		data->raycast->step_y = -1;
		data->raycast->sidedist_y = (data->player->loc_y - data->player->loc_ipy) \
			* data->raycast->deltadist_y;
	}
	else
	{
		data->raycast->step_y = 1;
		data->raycast->sidedist_y = (data->player->loc_ipy + 1.0 - data->player->loc_y) \
			* data->raycast->deltadist_y;
	}
}
