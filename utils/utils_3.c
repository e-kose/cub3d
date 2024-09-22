/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekose <ekose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 08:47:24 by ekose             #+#    #+#             */
/*   Updated: 2024/09/22 15:15:34 by ekose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

u_int32_t	**ft_mem2array(uint32_t *mem, size_t len_x, size_t len_y)
{
	u_int32_t	**arr;
	size_t		i;

	arr = malloc(len_y * sizeof(u_int32_t *));
	if (!arr)
		return (NULL);
	i = 0;
	while (i < len_y)
	{
		arr[i] = &(mem[i * len_x]);
		++i;
	}
	return (arr);
}

int	ft_errorimg_norm(t_cub *cub, int i, mlx_ptr_t *new_mlx)
{
	if (i == 0)
		return ((int)free_parsed(cub->pars));
	if (i == 1)
	{
		mlx_destroy_image(cub->mlx, new_mlx->font);
		mlx_destroy_window(cub->mlx, cub->mlxwin);
		free(cub->mlx);
		return ((int)free_parsed(cub->pars));
	}
	return (0);
}

int	ft_errorimg(t_cub *cub, int i)
{
	mlx_ptr_t	*new_mlx;
	int			j;

	new_mlx = cub->mlx;
	j = 0;
	if (i == 0 || i == 1)
		return (ft_errorimg_norm(cub, i, new_mlx));
	while (j < i && j <= 2)
	{
		mlx_destroy_image(cub->mlx, cub->image[j].img);
		free(cub->image[j].arr);
		j++;
	}
	while (j < i - 1)
	{
		mlx_destroy_image(cub->mlx, cub->texture[j - 3].img);
		free(cub->texture[j - 3].arr);
		j++;
	}
	mlx_destroy_image(cub->mlx, new_mlx->font);
	mlx_destroy_window(cub->mlx, cub->mlxwin);
	free(cub->mlx);
	return ((int)free_parsed(cub->pars));
}
