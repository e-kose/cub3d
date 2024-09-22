/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekose <ekose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 14:32:23 by ekose             #+#    #+#             */
/*   Updated: 2024/09/22 15:02:15 by ekose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	parse_only(t_parsed *pars)
{
	if (!pars)
		return (1);
	printf("MAP OK.\n");
	free_parsed(pars);
	return (0);
}

void	pdynpdy(t_cub *cub)
{
	cub->pos.pdx = cos(cub->pos.pa) * 5;
	cub->pos.pdy = sin(cub->pos.pa) * 5;
}

int	mouse_motion(int x, int y, t_cub *cub)
{
	static int	prev_x = 560;
	float		rot;

	(void)y;
	if (!cub->mouse_grabbed)
		return (0);
	rot = (prev_x - x) / (float)1000;
	if (rot < 0)
		rot *= -1;
	if (x > 960)
	{
		cub->pos.pa += rot;
		if (cub->pos.pa > 2 * PI)
			cub->pos.pa -= 2 * PI;
		pdynpdy(cub);
	}
	else if (x < 960)
	{
		cub->pos.pa -= rot;
		if (cub->pos.pa < 0)
			cub->pos.pa += 2 * PI;
		pdynpdy(cub);
	}
	prev_x = x;
	return (mlx_mouse_move(cub->mlxwin, 960, 540));
}

int	mouse_release(int key, int x, int y, void *param)
{
	t_cub	*cub;

	(void)x;
	(void)y;
	cub = param;
	if (key == MOUSE_LEFT)
	{
		if (cub->mouse_grabbed)
		{
			mlx_mouse_show();
			cub->mouse_grabbed = 0;
		}
		else
		{
			mlx_mouse_hide();
			mlx_mouse_move(cub->mlxwin, 960, 540);
			cub->mouse_grabbed = 1;
		}
	}
	return (0);
}

int	destroy(void *param)
{
	t_cub		*cub;
	mlx_ptr_t	*new_mlx;

	cub = param;
	new_mlx = cub->mlx;
	mlx_destroy_image(cub->mlx, cub->image[0].img);
	free(cub->image[0].arr);
	mlx_destroy_image(cub->mlx, cub->image[1].img);
	free(cub->image[1].arr);
	mlx_destroy_image(cub->mlx, cub->image[2].img);
	free(cub->image[2].arr);
	mlx_destroy_image(cub->mlx, cub->texture[0].img);
	free(cub->texture[0].arr);
	mlx_destroy_image(cub->mlx, cub->texture[1].img);
	free(cub->texture[1].arr);
	mlx_destroy_image(cub->mlx, cub->texture[2].img);
	free(cub->texture[2].arr);
	mlx_destroy_image(cub->mlx, cub->texture[3].img);
	free(cub->texture[3].arr);
	mlx_destroy_image(cub->mlx, cub->texture[4].img);
	free(cub->texture[4].arr);
	mlx_destroy_image(cub->mlx, new_mlx->font);
	mlx_destroy_window(cub->mlx, cub->mlxwin);
	return (free(cub->mlx), free_parsed(cub->pars), exit (0), 0);
}
