/*
 ███▄ ▄███▓▓█████  ███▄    █  ▄▄▄        ██████▓██   ██▓
▓██▒▀█▀ ██▒▓█   ▀  ██ ▀█   █ ▒████▄    ▒██    ▒ ▒██  ██▒
▓██    ▓██░▒███   ▓██  ▀█ ██▒▒██  ▀█▄  ░ ▓██▄    ▒██ ██░
▒██    ▒██ ▒▓█  ▄ ▓██▒  ▐▌██▒░██▄▄▄▄██   ▒   ██▒ ░ ▐██▓░
▒██▒   ░██▒░▒████▒▒██░   ▓██░ ▓█   ▓██▒▒██████▒▒ ░ ██▒▓░
░ ▒░   ░  ░░░ ▒░ ░░ ▒░   ▒ ▒  ▒▒   ▓▒█░▒ ▒▓▒ ▒ ░  ██▒▒▒
░  ░      ░ ░ ░  ░░ ░░   ░ ▒░  ▒   ▒▒ ░░ ░▒  ░ ░▓██ ░▒░
░      ░      ░      ░   ░ ░   ░   ▒   ░  ░  ░  ▒ ▒ ░░
       ░      ░  ░         ░       ░  ░      ░  ░ ░
                                                ░ ░*/

#include "inc/cub3d.h"

static void	ft_init_value(t_data *data)
{
	int	i;

	i = -1;
	data->map->_1d_map = ft_strdup("\n");
	data->map->map = NULL;
	data->node = NULL;
	while (++i < 6)
		data->texture->txt_count[i] = 0;
	data->map->map_width = 0;
	data->map->map_height = 0;
	data->map->cpymap = NULL;
	data->texture->north = NULL;
	data->texture->south = NULL;
	data->texture->west = NULL;
	data->texture->east = NULL;
	data->texture->floor = NULL;
	data->texture->ceiling = NULL;
	data->mlx = NULL;
	data->key->w = 0;
	data->key->a = 0;
	data->key->s = 0;
	data->key->d = 0;
	data->key->left = 0;
	data->key->right = 0;
	data->raycast->hit = 0;
}

static void	ft_init(t_data *data)
{
	data->map = malloc(sizeof(t_map));
	data->texture = malloc(sizeof(t_texture));
	data->player = malloc(sizeof(t_player));
	data->key = malloc(sizeof(t_key));
	data->raycast = malloc(sizeof(t_raycast));
	if (data->map == NULL || data->texture == NULL
		|| data->player == NULL || data->key == NULL
		|| data->raycast == NULL)
		ft_error_msg("Malloc error");
	ft_init_value(data);
}

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac != 2)
		ft_error_msg("Number of invalid arguments");
	data = malloc(sizeof(t_data));
	if (data == NULL)
		ft_error_msg("Malloc error");
	ft_init(data);
	ft_parse_map(av[1], data);
	# if defined(__APPLE__)
		if (ft_strncmp(av[1], "map/kvp.cub", 12) == 0)
			system("afplay ~/Desktop/cub3D/textures/kvp/kvp.mp3 & ps -ax | grep -v grep |grep afplay | awk '{print $1}' > kvp.txt");
	# endif
	ft_init_mlx(data);
	ft_free(data, NULL);
	return (0);
}
