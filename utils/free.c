/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekose <ekose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:53:00 by ekose             #+#    #+#             */
/*   Updated: 2024/10/17 17:26:19 by ekose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

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
	if (data->player != NULL)
		free(data->player);
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

void ft_free(t_data *data, char *s)
{
	ft_free_texture(data);
	ft_free_map(data);
	free(data);
	if (s != NULL)
		ft_error_msg(s);
}