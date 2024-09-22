/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekose <ekose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 03:16:15 by ekose             #+#    #+#             */
/*   Updated: 2024/09/22 14:40:01 by ekose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_hori(t_cub *cub)
{
	{
		cub->data.rayy = (((int)cub->pos.y >> 6) << 6) - 0.001;
		cub->data.rayx = (cub->pos.y - cub->data.rayy) \
			* cub->data.atan + cub->pos.x;
		cub->data.yo = -64;
		cub->data.xo = -cub->data.yo * cub->data.atan;
		cub->data.tmpdir1 = N;
	}
	if (cub->data.ra < PI)
	{
		cub->data.rayy = (((int)cub->pos.y >> 6) << 6) + 64;
		cub->data.rayx = (cub->pos.y - cub->data.rayy) \
			* cub->data.atan + cub->pos.x;
		cub->data.yo = 64;
		cub->data.xo = -cub->data.yo * cub->data.atan;
		cub->data.tmpdir1 = S;
	}
	if (cub->data.ra == 0 || cub->data.ra == PI)
	{
		cub->data.rayx = cub->pos.x;
		cub->data.rayy = cub->pos.y;
		cub->data.dow = cub->max;
	}
}

void	ft_hori_try_contact(t_cub *cub)
{
	while (cub->data.dow < cub->max)
	{
		cub->data.mx = (int)(cub->data.rayx) >> 6;
		cub->data.my = (int)(cub->data.rayy) >> 6;
		cub->data.mp = cub->data.my * cub->mapw + cub->data.mx;
		if (cub->data.mp > 0 && cub->data.mp < cub->mapw \
			* cub->maph && (cub->map[cub->data.mp] == 1
				|| cub->map[cub->data.mp] == 2))
		{
			if (cub->map[cub->data.mp] == 2)
				cub->data.tmpdir1 = DOOR;
			cub->data.horix = cub->data.rayx;
			cub->data.horiy = cub->data.rayy;
			cub->data.dish = dist(cub->pos.x, cub->pos.y, \
				cub->data.horix, cub->data.horiy);
			cub->data.dow = cub->max;
		}
		else
		{
			cub->data.rayx += cub->data.xo;
			cub->data.rayy += cub->data.yo;
			cub->data.dow += 1;
		}
	}
}

void	ft_verti(t_cub *cub)
{
	if (cub->data.ra > (PI / 2) && cub->data.ra < (3 * PI / 2))
	{
		cub->data.rayx = (((int)cub->pos.x >> 6) << 6) - 0.001;
		cub->data.rayy = (cub->pos.x - cub->data.rayx) \
			* cub->data.ntan + cub->pos.y;
		cub->data.xo = -64;
		cub->data.yo = -cub->data.xo * cub->data.ntan;
		cub->data.tmpdir2 = O;
	}
	if (cub->data.ra < (PI / 2) || cub->data.ra > (3 * PI / 2))
	{
		cub->data.rayx = (((int)cub->pos.x >> 6) << 6) + 64;
		cub->data.rayy = (cub->pos.x - cub->data.rayx) \
			* cub->data.ntan + cub->pos.y;
		cub->data.xo = 64;
		cub->data.yo = -cub->data.xo * cub->data.ntan;
		cub->data.tmpdir2 = E;
	}
	if (cub->data.ra == 0 || cub->data.ra == PI)
	{
		cub->data.rayx = cub->pos.x;
		cub->data.rayy = cub->pos.y;
		cub->data.dow = cub->max;
	}
}

void	ft_verti_try_contact(t_cub *cub)
{
	while (cub->data.dow < cub->max)
	{
		cub->data.mx = (int)(cub->data.rayx) >> 6;
		cub->data.my = (int)(cub->data.rayy) >> 6;
		cub->data.mp = cub->data.my * cub->mapw + cub->data.mx;
		if (cub->data.mp > 0 && cub->data.mp < cub->mapw \
			* cub->maph && (cub->map[cub->data.mp] == 1
				|| cub->map[cub->data.mp] == 2))
		{
			if (cub->map[cub->data.mp] == 2)
				cub->data.tmpdir2 = DOOR;
			cub->data.vertx = cub->data.rayx;
			cub->data.verty = cub->data.rayy;
			cub->data.disv = dist(cub->pos.x, cub->pos.y, \
				cub->data.vertx, cub->data.verty);
			cub->data.dow = cub->max;
		}
		else
		{
			cub->data.rayx += cub->data.xo;
			cub->data.rayy += cub->data.yo;
			cub->data.dow += 1;
		}
	}
}

void	ft_shorter(t_cub *cub)
{
	if (cub->data.disv > cub->data.dish)
	{
		if (cub->data.tmpdir1 == N)
			cub->data.dir = N;
		else if (cub->data.tmpdir1 == S)
			cub->data.dir = S;
		else if (cub->data.tmpdir1 == DOOR)
			cub->data.dir = DOOR;
		cub->data.rayx = cub->data.horix;
		cub->data.rayy = cub->data.horiy;
		cub->data.dist = cub->data.dish;
	}
	if (cub->data.disv <= cub->data.dish)
	{
		if (cub->data.tmpdir2 == E)
			cub->data.dir = E;
		else if (cub->data.tmpdir2 == O)
			cub->data.dir = O;
		else if (cub->data.tmpdir2 == DOOR)
			cub->data.dir = DOOR;
		cub->data.shade = 0.5;
		cub->data.rayx = cub->data.vertx;
		cub->data.rayy = cub->data.verty;
		cub->data.dist = cub->data.disv;
	}
}
