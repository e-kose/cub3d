/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehmyilm <mehmyilm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 12:38:10 by mehmyilm          #+#    #+#             */
/*   Updated: 2024/11/04 15:39:27 by mehmyilm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	ft_check_xpm(t_data *data)
{
	int	i;

	i = ft_strlen(data->texture->west) - 4;
	if (ft_strncmp((data->texture->west + i), ".xpm", 4) != 0 && i != 0)
		ft_free(data, "Invalid file extension");
	i = ft_strlen(data->texture->east) - 4;
	if (ft_strncmp(data->texture->east + i, ".xpm", 4) != 0 && i != 0)
		ft_free(data, "Invalid file extension");
	i = ft_strlen(data->texture->south) - 4;
	if (ft_strncmp((data->texture->south + i), ".xpm", 4) != 0 && i != 0)
		ft_free(data, "Invalid file extension");
	i = ft_strlen(data->texture->north) - 4;
	if (ft_strncmp((data->texture->north + i), ".xpm", 4) != 0 && i != 0)
		ft_free(data, "Invalid file extension");
}

int	ft_check_texture_count(t_data *data)
{
	int	i;
	int	*count;

	i = -1;
	count = data->texture->txt_count;
	while (++i < 6)
		if (count[i] != 1)
			return (0);
	return (1);
}

void	ft_take_texture(t_data *data, char *line, int *i)
{
	char	*key;
	char	*sub;

	while (line[*i] && (line[*i] != ' ' && !(line[*i] >= 9 && line[*i] <= 13)))
		(*i)++;
	key = ft_substr(line, 0, *i);
	while (line[*i] && (line[*i] == ' ' || (line[*i] >= 9 && line[*i] <= 13)))
		(*i)++;
	sub = ft_substr(line, *i, ft_strlen(line) - *i);
	if (ft_strcmp(key, "NO") == 0 && ++data->texture->txt_count[0])
		data->texture->north = ft_strdup(sub);
	else if (ft_strcmp(key, "SO") == 0 && ++data->texture->txt_count[1])
		data->texture->south = ft_strdup(sub);
	else if (ft_strcmp(key, "WE") == 0 && ++data->texture->txt_count[2])
		data->texture->west = ft_strdup(sub);
	else if (ft_strcmp(key, "EA") == 0 && ++data->texture->txt_count[3])
		data->texture->east = ft_strdup(sub);
	else if (ft_strcmp(key, "F") == 0 && ++data->texture->txt_count[4])
		data->texture->floor = ft_split(sub, ',');
	else if (ft_strcmp(key, "C") == 0 && ++data->texture->txt_count[5])
		data->texture->ceiling = ft_split(sub, ',');
	free(sub);
	free(key);
	free(line);
}

void	ft_check_texture(t_data *data)
{
	int	fd[4];
	int	i;
	int	check;

	check = 0;
	i = -1;
	ft_check_xpm(data);
	fd[++i] = open(data->texture->north, O_RDONLY, 777);
	fd[++i] = open(data->texture->south, O_RDONLY, 777);
	fd[++i] = open(data->texture->west, O_RDONLY, 777);
	fd[++i] = open(data->texture->east, O_RDONLY, 777);
	while (i >= 0)
	{
		if (fd[i] == -1)
			check++;
		close(fd[i]);
		i--;
	}
	if (check != 0)
		ft_free(data, "Texture file not found");
}
