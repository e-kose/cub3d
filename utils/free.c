/*########       ##    ##  #######   ######  ########
##               ##   ##  ##     ## ##    ## ##
##               ##  ##   ##     ## ##       ##
######  #######  #####    ##     ##  ######  ######
##               ##  ##   ##     ##       ## ##
##               ##   ##  ##     ## ##    ## ##
########         ##    ##  #######   ######  ########*/

#include "../inc/cub3d.h"

void	ft_free_double_str(char **s)
{
	int	i;

	i = 0;
	while (s[i] != NULL)
	{
		free(s[i]);
		i++;
	}
	free(s);
	s = NULL;
}

static void	ft_free_map(t_data *data)
{
	if (data->map->_1d_map != NULL)
		free(data->map->_1d_map);
	if (data->map->map != NULL)
		ft_free_double_str(data->map->map);
	if (data->map->cpymap != NULL)
		ft_free_double_str(data->map->cpymap);
	free(data->map);
	data->map = NULL;
}

static void	ft_free_texture(t_data *data)
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
	data->texture->ceiling = NULL;
	data->texture->floor = NULL;
	free(data->texture);
}

void	ft_mlx_free(t_data *data)
{
	int	i;

	i = 0;
	if (data->mlx == NULL)
		return ;
	if (data->mlx->win != NULL)
		mlx_destroy_window(data->mlx->mlx_ptr, data->mlx->win);
	if (data->mlx->img != NULL)
		mlx_destroy_image(data->mlx->mlx_ptr, data->mlx->img);
	while (i < 4)
	{
		if (data->img[i] != NULL)
		{
			if (data->img[i]->img != NULL)
				mlx_destroy_image(data->mlx->mlx_ptr, data->img[i]->img);
			free(data->img[i]);
		}
		i++;
	}
	free(data->mlx);
	data->mlx = NULL;
}

void	ft_free(t_data *data, char *s)
{
	ft_mlx_free(data);
	free(data->key);
	ft_free_texture(data);
	ft_free_list(data);
	free(data->raycast);
	free(data->player);
	ft_free_map(data);
	free(data);
	# if defined(__APPLE__)
		if (ft_strncmp(data->argv, "map/kvp.cub", 12) == 0)
		{
			system("kill -9 $(cat kvp.txt)");
			unlink("kvp.txt");
		}
	# endif

	data = NULL;
	if (s != NULL)
		ft_error_msg(s);
	exit(0);
}
