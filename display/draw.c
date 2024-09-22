/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekose <ekose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 03:32:52 by ekose             #+#    #+#             */
/*   Updated: 2024/09/22 14:38:58 by ekose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_drawwalls(t_cub *cub, int beginx, int beginy, int lineH)
{
	int		x;
	int		y;
	size_t	tmp_x;
	size_t	tmp_y;

	x = beginx;
	while (x < beginx + 4)
	{
		y = beginy - lineH;
		if (y < 0)
			y = 0;
		if (y > 1080)
			y = 1080;
		while (y < beginy + lineH && y < 1080)
		{
			tmp_x = ((double)((double)(cub->data.ratiox / 32)) \
				*cub->texture[cub->data.dir].widt);
			tmp_y = (((double)1 + ((double)(y - beginy - lineH) / \
					(double)(2 * lineH))) * \
						cub->texture[cub->data.dir].heig);
			cub->image[0].arr[y++][x] = \
					cub->texture[cub->data.dir].arr[tmp_y][tmp_x];
		}
		x++;
	}
}

void	ft_drawsquare(uint32_t **img_color, int posx, int posy, int scale)
{
	int	x;
	int	y;

	x = posx;
	y = posy;
	while (y < 1080)
	{
		x = posx;
		while (x < 1920)
		{
			if (y <= posy + scale && x <= posx + scale)
				img_color[y][x++] = 0xF3F3F2;
			else
				img_color[y][x++] = 0xFF000000;
		}
		++y;
	}
}

void	ft_drawmap(t_cub *cub)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	y = 0;
	while (y < cub->maph)
	{
		x = 0;
		while (x < cub->mapw)
		{
			cub->data.xo = x * cub->mapscale / cub->resizemap;
			cub->data.yo = y * cub->mapscale / cub->resizemap;
			if (cub->map[y * cub->mapw + x] == 1)
				ft_drawsquare(cub->image[1].arr, cub->data.xo, \
						cub->data.yo, 64 / cub->resizemap);
			x++;
		}
		y++;
	}
}

void	ft_draw_font(t_cub *cub)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < 1080)
	{
		x = 0;
		while (x < 1920)
		{
			if (y >= 540)
				cub->image[2].arr[y][x++] = cub->pars->floor_color;
			else
				cub->image[2].arr[y][x++] = cub->pars->ceil_color;
		}
		++y;
	}
}

void	playerdir(t_cub *cub)
{
	if (cub->pars->player.dir == 'E')
		cub->pos.pa = 0;
	if (cub->pars->player.dir == 'W')
		cub->pos.pa = PI;
	if (cub->pars->player.dir == 'N')
		cub->pos.pa = -PI / 2;
	if (cub->pars->player.dir == 'S')
		cub->pos.pa = PI / 2;
}