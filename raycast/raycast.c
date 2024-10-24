/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehmyilm <mehmyilm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 18:56:39 by mehmyilm          #+#    #+#             */
/*   Updated: 2024/10/24 19:26:32 by mehmyilm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void ft_put_pixel(t_data *data, int x, int y, int color)
{
    char *dst;

    // Pikselin bellekteki adresini hesaplıyoruz
    dst = data->mlx->addr + (y * data->mlx->line_length + x * (data->mlx->bits_per_pixel / 8));
    *(unsigned int *)dst = color;
}
void ft_init_mlx(t_data *data)
{
	// data->mlx->img = mlx_new_image(data->mlx, 1080, 720);
    data->mlx = mlx_init();
    if (!data->mlx)
        ft_free(data, "Mlx init failed");
    data->mlx->win = mlx_new_window(data->mlx, 1080, 720, "Cub3D");
    if (!data->mlx->win)
        ft_free(data, "Window creation failed");
	data->mlx->img = mlx_new_image(data->mlx, 1080, 720);
    data->mlx->addr = mlx_get_data_addr(data->mlx->img, &data->mlx->bits_per_pixel, &data->mlx->line_length, &data->mlx->endian);
	int i = -1;
	while (++i< 400)
		ft_put_pixel(data, 1080 - i, i, 0XFFFFFF);
    mlx_put_image_to_window(data->mlx, data->mlx->win, data->mlx->img, 0, 0);
    mlx_loop(data->mlx);
}
