/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekose <ekose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 21:45:38 by ekose             #+#    #+#             */
/*   Updated: 2024/09/22 15:01:30 by ekose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	my_mlx_pixel_put(t_image *image, int x, int y, int color)
{
	char	*dst;

	dst = image->addr + (y * image->line_length + x \
			* (image->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	ft_draw_line(t_cub *cub, t_pos pos, int endx, int endy)
{
	float	deltax;
	float	deltay;
	float	pixelx;
	float	pixely;
	int		pixels;

	pixelx = pos.x / cub->resizemap;
	pixely = pos.y / cub->resizemap;
	deltax = endx - pixelx;
	deltay = endy - pixely;
	pixels = sqrt((deltax * deltax)
			+ (deltay * deltay));
	deltax /= pixels;
	deltay /= pixels;
	pixelx = pos.x / cub->resizemap;
	pixely = pos.y / cub->resizemap;
	while (pixels)
	{
		my_mlx_pixel_put(&cub->image[0], pixelx, pixely, 0xff0000);
		pixelx += deltax;
		pixely += deltay;
		--pixels;
	}
	return ;
}

void	ft_doormanagernorm(t_cub *cub)
{
	if ((cub->map[cub->pos.ipy * cub->mapw + cub->pos.ipx_add_xo] == 3 && \
	(cub->map[cub->posy * cub->mapw + cub->posx] == 0 || cub->map[cub->posy \
	* cub->mapw + cub->posx] == 3)) || (cub->map[cub->pos.ipy_add_yo * \
	cub->mapw + cub->pos.ipx] == 3 && (cub->map[cub->posy * cub->mapw + \
	cub->posx] == 0 || cub->map[cub->posy * cub->mapw + cub->posx] == 3)))
	{
		if (cub->map[cub->pos.ipy * cub->mapw + cub->pos.ipx_add_xo] == 3 \
		&& cub->posy * cub->mapw + cub->posx != (int)(cub->pos.ipy * \
		cub->mapw + cub->pos.ipx_add_xo))
			cub->map[cub->pos.ipy * cub->mapw + cub->pos.ipx_add_xo] = 2;
		if (cub->map[cub->pos.ipy_add_yo * cub->mapw + cub->pos.ipx] == 3 \
		&& cub->posy * cub->mapw + cub->posx != (int)(cub->pos.ipy_add_yo * \
		cub->mapw + cub->pos.ipx))
			cub->map[cub->pos.ipy_add_yo * cub->mapw + cub->pos.ipx] = 2;
	}
}

void	ft_doormanager(t_cub *cub)
{
	cub->posx = (int)(cub->pos.x / 64.0);
	cub->posy = (int)(cub->pos.y / 64.0);
	if (cub->posy * cub->mapw + cub->posx != (cub->pos.ipy * cub->mapw + \
	cub->pos.ipx_add_xo) || cub->posy * cub->mapw + cub->posx != \
	(cub->pos.ipy_add_yo * cub->mapw + cub->pos.ipx))
	{
		if ((cub->map[cub->pos.ipy * cub->mapw + cub->pos.ipx_add_xo] == 2 && \
		(cub->map[cub->posy * cub->mapw + cub->posx] == 0 || cub->map[cub->posy \
		* cub->mapw + cub->posx] == 3)) || (cub->map[cub->pos.ipy_add_yo * \
		cub->mapw + cub->pos.ipx] == 2 && (cub->map[cub->posy * cub->mapw \
		+ cub->posx] == 0 || cub->map[cub->posy * cub->mapw + cub->posx] == 3)))
		{
			if (cub->map[cub->pos.ipy * cub->mapw + cub->pos.ipx_add_xo] == 2 \
			&& cub->posy * cub->mapw + cub->posx != (cub->pos.ipy * cub->mapw + \
			cub->pos.ipx_add_xo))
				cub->map[cub->pos.ipy * cub->mapw + cub->pos.ipx_add_xo] = 3;
			if (cub->map[cub->pos.ipy_add_yo * cub->mapw + cub->pos.ipx] == 2 \
			&& cub->posy * cub->mapw + cub->posx != (int)(cub->pos.ipy_add_yo \
			* cub->mapw + cub->pos.ipx))
				cub->map[cub->pos.ipy_add_yo * cub->mapw + cub->pos.ipx] = 3;
		}
		else
			ft_doormanagernorm(cub);
	}
		cub->clavier[6] = 0;
}

int	render_next_frame(t_cub *cub)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	ft_keyvalidation(cub);
	mlx_clear_window(cub->mlx, cub->mlxwin);
	drawrays(cub);
	mlx_put_image_to_window(cub->mlx, cub->mlxwin, cub->image[2].img, 0, 0);
	mlx_put_image_to_window(cub->mlx, cub->mlxwin, cub->image[0].img, 0, 0);
	if (cub->display_map)
		mlx_put_image_to_window(cub->mlx, cub->mlxwin, cub->image[1].img, 0, 0);
	while (y < 1080)
	{
		x = 0;
		while (x < 1920)
			cub->image[0].arr[y][x++] = 0xff000000;
		++y;
	}
	return (0);
}
