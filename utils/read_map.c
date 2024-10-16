/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekose <ekose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:58:08 by ekose             #+#    #+#             */
/*   Updated: 2024/10/16 17:52:31 by ekose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void ft_take_texture(t_data *data, char *line, int *i)
{
	char 	*key;
	char 	*sub;

	while (line[*i] && (line[*i] != ' ' && !(line[*i] >= 9 && line[*i] < 13)))
		(*i)++;
	key = ft_substr(line, 0, *i);
	while (line[*i] && (line[*i] == ' ' || (line[*i] >= 9 && line[*i] < 13)))
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
void ft_read_map(t_data *data)
{
	char *line;
	int i;

	line = get_next_line(data->fd);
	while(line != NULL)
	{
		i = 0;
		ft_take_texture(data, ft_strtrim(line, "\n"), &i);
		free(line);
		line = get_next_line(data->fd);
	}
	free(line);
	close(data->fd);
	i = -1;
	while (++i < 6)
		if (data->texture->txt_count[i] != 1)
			ft_free(data, "Texture count error");
}
