/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekose <ekose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 20:17:27 by ekose             #+#    #+#             */
/*   Updated: 2024/09/22 16:41:57 by ekose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"
void	drawrays(t_cub *cub)
{
	cub->data.ra = cub->pos.pa - 0.0043633231 * (240 >> 1);
	fix_angle(cub);
	cub->data.focal = 0;
	while (cub->data.focal < 480)
	{
		reset_raycasting_varshori(cub);
		ft_hori(cub);
		ft_hori_try_contact(cub);
		reset_raycasting_varsverti(cub);
		ft_verti(cub);
		ft_verti_try_contact(cub);
		cub->data.shade = 1;
		ft_shorter(cub);
		if (cub->display_map)
			ft_draw_line(cub, cub->pos, cub->data.rayx / cub->resizemap, \
				cub->data.rayy / cub->resizemap);
		cub->data.ratiox = (int)(cub->data.rayx / 2) % 32;
		ft_final_maths(cub);
		ft_drawwalls(cub, cub->data.focal * 4, \
			cub->data.lineo, cub->data.lineh);
		cub->data.ra += 0.0043633231 / 2;
		fix_angle(cub);
		cub->data.focal++;
	}
}

void	ft_recup(t_cub *cub)
{
	cub->pars->player.y += 1;
	cub->pos.pdx = cos(cub->pos.pa) * 5;
	cub->pos.pdy = sin(cub->pos.pa) * 5;
	cub->data.focal = 0;
	cub->mapw = cub->pars->map1d->width;
	cub->maph = cub->pars->map1d->height;
	cub->mapscale = 64;
	cub->pos.x = cub->mapscale * ((double)cub->pars->player.x + 0.5);
	cub->pos.y = cub->mapscale * ((double)cub->pars->player.y - 0.5);
	cub->mouse_grabbed = 0;
	cub->display_map = 0;
}

void	init(t_cub *cub)
{
	int	i;

	i = 2;
	cub->checkimg = 0;
	cub->mlx = mlx_init();
	if (!cub->mlx)
		return ;
	cub->checkimg = 1;
	cub->mlxwin = mlx_new_window(cub->mlx, 1920, 1080, "Cub3D");
	playerdir(cub);
	ft_recup(cub);
	if (cub->maph > cub->mapw)
		cub->max = cub->maph;
	else
		cub->max = cub->mapw;
	cub->resizemap = 2;
	while (cub->max / i > 25)
	{
		cub->resizemap += 1;
		i += 1;
	}
	cub->map = cub->pars->map1d->map;
	init_imagespartone(cub, &cub->checkimg);
	ft_bzero(cub->clavier, sizeof(char) * 7);
	return ;
}

int	main(int argc, char **argv)
{
	t_cub	cub;

	if (argc == 3 && !ft_strncmp("-p", argv[1], 2) && ft_strlen(argv[1]) == 2)
	{
		cub.pars = parse(argv[2]);
		return (parse_only(cub.pars));
	}
	else if (argc != 2)
		return (printf("Usage: ./cub3d [-p] <map path>\n"));
	cub.pars = parse(argv[1]);
	if (!cub.pars)
		return (1);
	init(&cub);
	if (cub.checkimg != 9)
		return (ft_errorimg(&cub, cub.checkimg));
	ft_draw_font(&cub);
	ft_drawmap(&cub);
	mlx_hook(cub.mlxwin, 2, 1L << 0, key_hook, &cub);
	mlx_hook(cub.mlxwin, 3, 2L << 0, key_hook_release, &cub);
	mlx_hook(cub.mlxwin, ON_DESTROY, 0L, destroy, &cub);
	mlx_loop_hook(cub.mlx, render_next_frame, &cub);
	mlx_loop(cub.mlx);
	return (0);
}
