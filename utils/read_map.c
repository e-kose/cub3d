/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehmyilm <mehmyilm@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:58:08 by ekose             #+#    #+#             */
/*   Updated: 2024/10/20 23:57:37 by mehmyilm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"


static int	ft_check_texture_count(t_data *data)
{
	int i;
	int *count;

	i = -1;
	count = data->texture->txt_count;
	while (++i < 6)
		if (count[i] != 1)
			return (0);
	return (1);
}

static void ft_map_feature(t_data *data)
{
	int i;
	int j;
	int count;

	i = -1;
	count = 0;
	while(data->map->map[++i])
	{
		j = -1;
		while(data->map->map[i][++j])
		{
			if (data->map->map[i][j] == 'N' || data->map->map[i][j] == 'S'
				|| data->map->map[i][j] == 'E' || data->map->map[i][j] == 'W')
			{
				data->player = malloc(sizeof(int) * 2);
				data->player[0] = i;
				data->player[1] = j;
				data->player_dir = data->map->map[i][j];
				count++;
			}
		}
	}
	if (count != 1)
		ft_free(data, "Multiple player error");
	data->map->map_height = i;
}

static void	ft_take_map(t_list **node, char *line)
{
	t_list	*new_node;

	new_node = ft_lstnew(line);
	if (!new_node)
		ft_error_msg("Malloc error");
	ft_lstadd_back(node, new_node);
}

static void	ft_map_fill(t_data *data, char *line)
{
	static int check = 0;
	int 		i;
	char		*symbol;
	char		*tmp;

	i = -1;
	symbol = "01NSEW";
	while(symbol[++i] && check == 0)
		if (ft_strchr(line, symbol[i]) != NULL)
			check++;
	if (check > 0)
	{
		ft_take_map(&data->node, ft_strdup(line));
		// if(line[0] == '\n' )
		// 	ft_free(data, "Multiple map error");
		ft_check_line(data, line);
		tmp = ft_strjoin(data->map->_1d_map, line);
		free(data->map->_1d_map);
		data->map->_1d_map = ft_strdup(tmp);
		free(tmp);
	}
}


static void ft_take_texture(t_data *data, char *line, int *i)
{
	char 	*key;
	char 	*sub;

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
void ft_read_map(t_data *data)
{
	char *line;
	int i;

	data->node = malloc(sizeof(t_list));
	if (!data->node)
		ft_error_msg("Malloc error");
	data->node = NULL;
	data->fd = open(data->argv, O_RDONLY);
	line = get_next_line(data->fd);
	while(line != NULL)
	{
		i = 0;
		if (ft_check_texture_count(data) == 1)
			ft_map_fill(data, line);
		else
			ft_take_texture(data, ft_strtrim(line, "\n"), &i);
		free(line);
		line = get_next_line(data->fd);

	}
	free(line);
	close(data->fd);
	printf("map_1d: %s\n", data->map->_1d_map);
	printf("node_listed: \n");
	while(data->node)
	{
		printf("node: %s\n", (char *)data->node->content);
		data->node = data->node->next;
	}
	printf("node_tmp: %s\n", (char *)data->node->content);
	data->map->map = ft_split(data->map->_1d_map, '\n');
	if (ft_check_texture_count(data) == 0)
		ft_free(data, "Texture count error");
	ft_map_feature(data);



}
