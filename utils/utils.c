/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekose <ekose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 22:51:43 by ekose             #+#    #+#             */
/*   Updated: 2024/09/22 14:42:29 by ekose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_final_maths(t_cub *cub)
{
	cub->data.ca = cub->pos.pa - cub->data.ra;
	if (cub->data.ca < 0)
		cub->data.ca += 2 * PI;
	if (cub->data.ca > 2 * PI)
		cub->data.ca -= 2 * PI;
	cub->data.dist = cub->data.dist * cos(cub->data.ca) / 2;
	cub->data.lineh = (cub->mapscale * 340) / cub->data.dist;
	cub->data.lineo = 540;
	if (cub->data.shade == 1)
	{
		cub->data.ratiox = (int)(cub->data.rayx / 2.0) % 32;
		if (cub->data.ra > 180)
			cub->data.ratiox = 31 - cub->data.ratiox;
	}
	else
	{
		cub->data.ratiox = (int)(cub->data.rayy / 2.0) % 32;
		if (cub->data.ra > 90 && cub->data.ra < 270)
			cub->data.ratiox = 31 - cub->data.ratiox;
	}
}

void	reset_raycasting_varshori(t_cub *cub)
{
	cub->data.dow = 0;
	cub->data.dish = 1000000;
	cub->data.horix = cub->pos.x + 32;
	cub->data.horiy = cub->pos.y;
	cub->data.atan = -1 / tan(cub->data.ra);
}

void	reset_raycasting_varsverti(t_cub *cub)
{
	cub->data.dow = 0;
	cub->data.disv = 1000000;
	cub->data.vertx = cub->pos.x + 32;
	cub->data.verty = cub->pos.y;
	cub->data.ntan = -tan(cub->data.ra);
}

void	fix_angle(t_cub *cub)
{
	if (cub->data.ra < 0)
		cub->data.ra += 2 * PI;
	if (cub->data.ra > 2 * PI)
		cub->data.ra -= 2 * PI;
}

float	dist(float ax, float ay, float bx, float by)
{
	return (sqrt((bx - ax) * (bx - ax) + (by - ay) * (by - ay)));
}
