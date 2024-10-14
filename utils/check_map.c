/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekose <ekose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:39:49 by ekose             #+#    #+#             */
/*   Updated: 2024/10/14 18:38:58 by ekose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"
// static void ft_check_rgb(t_data *data)
// {
// 	int i;
// 	int j;
// 	int check;
	
// 	i = -1;
// 	check = 0;
// 	while(++i < 3)
// 	{
// 		j = -1;
// 		while(++j < 3)
// 		{
// 			if(data->texture->floor[i][j] < 0 || data->texture->floor[i][j] > 255)
// 				check++;
// 			if(data->texture->ceiling[i][j] < 0 || data->texture->ceiling[i][j] > 255)
// 				check++;
// 		}
// 	}
// 	if(check != 0)
// 		ft_free(data, "RGB value must be between 0 and 255");
// }
// static void ft_check_texture(t_data *data)
// {
// 	int	fd[4];
// 	int i;
// 	int check;
	
// 	i = -1;
// 	check = 0;
// 	fd[++i] = open(data->texture->north, O_RDONLY, 777);
// 	fd[++i] = open(data->texture->south, O_RDONLY, 777);
// 	fd[++i] = open(data->texture->west, O_RDONLY, 777);
// 	fd[++i] = open(data->texture->east, O_RDONLY, 777);
// 	while(i >= 0)
// 	{
// 		if(fd[i] == -1)
// 			check++;
// 		close(fd[i]);
// 		i--;
// 	}
// 	if(check != 0)
// 		ft_free(data, "Texture file not found");
// }
void ft_parse_map(char *av, t_data *data)
{	
	data->argv = av;
	size_t		i;

	i = ft_strlen(data->argv) - 4;
	if (ft_strncmp(&(data->argv[i]), ".cub", 4) != 0 && i != 0)
		ft_free(data, "Invalid file extension");
	data->fd = open(data->argv, O_RDONLY, 777);
	if(data->fd == -1)
		ft_free(data, "File not found");
	ft_read_map(data);
	// ft_check_texture(data);
	// ft_check_rgb(data);
	//!!!-------------RGB int çevirlecek----------- !!!!!!!!
}
