/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekose <ekose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:56:03 by ekose             #+#    #+#             */
/*   Updated: 2024/10/16 18:48:57 by ekose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/cub3d.h"

static void ft_init(t_data *data)
{
	int i;

	i = -1;
	data->map = malloc(sizeof(t_map));
	data->texture = malloc(sizeof(t_texture));
	if(data->map == NULL || data->texture == NULL)
		ft_error_msg("Malloc error");
	while(++i < 6)
		data->texture->txt_count[i] = 0;
	data->texture->north = NULL;
	data->texture->south = NULL;
	data->texture->west = NULL;
	data->texture->east = NULL;
	data->texture->floor = NULL;
	data->texture->ceiling = NULL;
	
}
int main(int ac, char **av)
{
	t_data *data;

	if (ac != 2)
		ft_error_msg("Number of invalid arguments");
	data = malloc(sizeof(t_data));
	if(data == NULL)
		ft_error_msg("Malloc error");
	ft_init(data);
	ft_parse_map(av[1], data);
	printf("NO: %s\n", data->texture->north);
	printf("SO: %s\n", data->texture->south);
	printf("WE: %s\n", data->texture->west);
	printf("EA: %s\n", data->texture->east);
	printf("F: %d\n", data->texture->floor_color[1]);
	printf("C: %d\n", data->texture->ceiling_color[2]);
	ft_free(data, NULL);
	return (0);
}