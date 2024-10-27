/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehmyilm <mehmyilm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:53:00 by ekose             #+#    #+#             */
/*   Updated: 2024/10/27 14:35:16 by mehmyilm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"
void	ft_free_list(t_data *data)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = data->node;
	while (tmp)
	{

		free(tmp->content);
		tmp2 = tmp;
		tmp = tmp->next;
		free(tmp2);
	}
}
void ft_free_double_str(char **s)
{
	int i;

	i = 0;
	while (s[i] != NULL)
	{
		free(s[i]);
		i++;
	}
	{
		free(s[i]);
		i++;
	}
	free(s);
}
static void ft_free_map(t_data *data)
{
	if (data->map->_1d_map != NULL)
		free(data->map->_1d_map);
	if (data->map->map != NULL)
		ft_free_double_str(data->map->map);
	if (data->map->cpymap != NULL)
		ft_free_double_str(data->map->cpymap);
	free(data->map);
}
static void ft_free_texture(t_data *data)
{
	if (data->texture->north != NULL)
		free(data->texture->north);
	if (data->texture->south != NULL)
		free(data->texture->south);
	if (data->texture->west != NULL)
		free(data->texture->west);
	if (data->texture->east != NULL)
		free(data->texture->east);
	if (data->texture->floor != NULL)
		ft_free_double_str(data->texture->floor);
	if (data->texture->ceiling != NULL)
		ft_free_double_str(data->texture->ceiling);
	free(data->texture);
}

void	ft_mlx_free(t_data *data)
{
	if (data->mlx == NULL)
		return ;
	if (data->mlx->win != NULL)
		mlx_destroy_window(data->mlx->mlx, data->mlx->win);
	if (data->mlx->img != NULL)
		mlx_destroy_image(data->mlx->mlx, data->mlx->img);
	free(data->mlx);
}

void	ft_free(t_data *data, char *s)
{
	ft_free_texture(data);
	ft_free_map(data);
	ft_free_list(data);
	ft_mlx_free(data);
	free(data->player);
	free(data);
	if (s != NULL)
		ft_error_msg(s);
}
