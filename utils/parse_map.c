/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehmyilm <mehmyilm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:39:49 by ekose             #+#    #+#             */
/*   Updated: 2024/10/19 18:46:30 by mehmyilm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

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
static void ft_check_rgb(t_data *data, char **rgb)
{
	int	i;
	int	j;

	i = -1;
	while (rgb[++i])
	{
		j = -1;
		while ((rgb[i][++j]))
		{
			if (!ft_isdigit((rgb[i][j])))
			{
				if (rgb[i][j] == '-')
					ft_free(data, "RGB value must be between 0 and 255");
				if (!((rgb[i][j] >= 9 && rgb[i][j] <= 13) || rgb[i][j] == 32))
					ft_free(data, "RGB value must be digit");
			}
		}
	}
}
static void ft_convert_rgb(t_data *data, char **rgb, char c)
{
	int i;

	i = -1;
	ft_check_rgb(data, rgb);
	while (rgb[++i])
	{
		if (ft_atoi(rgb[i]) < 0 || ft_atoi(rgb[i]) > 255)
			ft_free(data, "RGB value must be between 0 and 255");
	}
	i = -1;
	while (rgb[++i])
	{
		if (c == 'F')
			data->texture->floor_color[i] = ft_atoi(rgb[i]);
		else if (c == 'C')
			data->texture->ceiling_color[i] = ft_atoi(rgb[i]);
	}
}
static char **ft_clean_rgb(t_data *data, char **str)
{
	int		i;
	char	**tmp;

	i = -1;
	tmp = malloc(sizeof(char *) * 4);
	if (tmp == NULL)
		ft_free(data, "Malloc error");
	while (str[++i])
	{
		tmp[i] = ft_strtrim(str[i], " ");
		free(str[i]);
		if (tmp[i] == NULL)
			ft_free(data, "Malloc error");
	}
	tmp[i] = NULL;
	free(str);
	if (i != 3)
		ft_free(data, "RGB value must be 3");
	return (tmp);
}

void	ft_parse_map(char *av, t_data *data)
{
	size_t		i;
	int			fd;

	data->argv = av;
	i = ft_strlen(data->argv) - 4;
	if (ft_strncmp(&(data->argv[i]), ".cub", 4) != 0 && i != 0)
		ft_free(data, "Invalid file extension");
	fd = open(data->argv, O_RDONLY, 777);
	if (fd == -1)
		ft_free(data, "File not found");
	ft_read_map(data);
	ft_check_wall(data, data->map->map);
	ft_fill_space(data->map);
	ft_flood_fill(data->player[0], data->player[1], data->map);
	ft_check_fill(data);
	// ft_check_texture(data);
	data->texture->floor = ft_clean_rgb(data, data->texture->floor);
	data->texture->ceiling = ft_clean_rgb(data, data->texture->ceiling);
	ft_convert_rgb(data, data->texture->floor, 'F');
	ft_convert_rgb(data, data->texture->ceiling, 'C');

}
