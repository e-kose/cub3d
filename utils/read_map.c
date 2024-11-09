/*########       ##    ##  #######   ######  ########
##               ##   ##  ##     ## ##    ## ##
##               ##  ##   ##     ## ##       ##
######  #######  #####    ##     ##  ######  ######
##               ##  ##   ##     ##       ## ##
##               ##   ##  ##     ## ##    ## ##
########         ##    ##  #######   ######  ########*/

#include "../inc/cub3d.h"

static void	ft_map_feature(t_data *data, int count)
{
	int	i;
	int	j;

	i = -1;
	while (data->map->map[++i])
	{
		j = -1;
		while (data->map->map[i][++j])
		{
			if (data->map->map[i][j] == 'N' || data->map->map[i][j] == 'S'
				|| data->map->map[i][j] == 'E' || data->map->map[i][j] == 'W')
			{
				data->plyr_loc[0] = i;
				data->plyr_loc[1] = j;
				data->player_dir = data->map->map[i][j];
				count++;
			}
		}
	}
	if (count == 0 && i == 0)
		ft_free(data, "Map not found");
	else if (count != 1)
		ft_free(data, "Player error");
	data->map->map_height = i;
}

static void	ft_map_fill(t_data *data, char *line)
{
	static int	check = 0;
	int			i;
	char		*symbol;
	char		*tmp;

	i = -1;
	symbol = "01NSEW";
	while (symbol[++i] && check == 0)
		if (ft_strchr(line, symbol[i]) != NULL)
			check++;
	if (check > 0)
	{
		ft_take_map(&data->node, ft_strdup(line));
		ft_check_char(data, line);
		tmp = ft_strjoin(data->map->_1d_map, line);
		free(data->map->_1d_map);
		data->map->_1d_map = ft_strdup(tmp);
		free(tmp);
	}
}

void	ft_read_map(t_data *data)
{
	char	*line;
	int		i;

	data->fd = open(data->argv, O_RDONLY);
	line = get_next_line(data->fd);
	while (line != NULL)
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
	ft_check_line(data);
	data->map->map = ft_split(data->map->_1d_map, '\n');
	if (ft_check_texture_count(data) == 0)
		ft_free(data, "Texture count error");
	ft_map_feature(data, 0);
	data->player->loc_x = (double)data->plyr_loc[1];
	data->player->loc_y = (double)data->plyr_loc[0];
}

void	ft_take_map(t_list **node, char *line)
{
	t_list	*new_node;

	new_node = ft_lstnew(line);
	ft_lstadd_back(node, new_node);
}
