/*########       ##    ##  #######   ######  ########
##               ##   ##  ##     ## ##    ## ##
##               ##  ##   ##     ## ##       ##
######  #######  #####    ##     ##  ######  ######
##               ##  ##   ##     ##       ## ##
##               ##   ##  ##     ## ##    ## ##
########         ##    ##  #######   ######  ########*/

#include "../inc/cub3d.h"

static void	ft_xpm_to_img(t_data *data, char *path, int index)
{
	data->img[index] = malloc(sizeof(t_img));
	if (!data->img[index])
		ft_free(data, "Malloc doesn't work!");
	data->img[index]->img = mlx_xpm_file_to_image(data->mlx->mlx_ptr, path,
			&data->img[index]->xpm_w, &data->img[index]->xpm_h);
	if (!data->img[index]->img)
		ft_free(data, "Texture doesn't work!");
	data->img[index]->addr = \
	(int *)mlx_get_data_addr(data->img[index]->img, \
	&data->img[index]->bpp, &data->img[index]->line_length, \
	&data->img[index]->endian);
	if (!data->img[index]->addr)
		ft_free(data, "Texture doesn't work!");
}

static void	ft_set_img(t_data *data)
{
	ft_xpm_to_img(data, data->texture->west, 1);
	ft_xpm_to_img(data, data->texture->east, 0);
	ft_xpm_to_img(data, data->texture->south, 3);
	ft_xpm_to_img(data, data->texture->north, 2);
}

void	ft_init_mlx(t_data *data)
{
	data->mlx = malloc(sizeof(t_mlx));
	if (!data->mlx)
		ft_free(data, "Malloc error");
	data->mlx->mlx_ptr = mlx_init();
	if (!data->mlx->mlx_ptr)
		ft_free(data, "Mlx init failed");
	data->mlx->win = mlx_new_window(data->mlx->mlx_ptr, WIDTH, HEIGHT, "Cub3D");
	if (!data->mlx->win)
		ft_free(data, "Window creation failed");
	data->mlx->img = mlx_new_image(data->mlx->mlx_ptr, WIDTH, HEIGHT);
	data->mlx->addr = (int *)mlx_get_data_addr(data->mlx->img, &data->mlx->bpp,
			&data->mlx->line_length, &data->mlx->endian);
	if (!data->mlx->img)
		ft_free(data, "Image creation failed");
	ft_set_img(data);

	# if defined(__APPLE__)
		mlx_loop_hook(data->mlx->mlx_ptr, ft_game_handler, data);
		mlx_hook(data->mlx->win, 2, 0, ft_key_pressed_mac, data);
		mlx_hook(data->mlx->win, 3, 0, ft_key_released_mac, data);
		mlx_hook(data->mlx->win, 17, 0, ft_exit_game, data);
	# elif defined(__linux__)
		mlx_loop_hook(data->mlx->mlx_ptr, ft_game_handler, data);
		mlx_hook(data->mlx->win, KeyRelease, KeyPressMask, ft_key_released_linux, data);
		mlx_hook(data->mlx->win, KeyPress, KeyReleaseMask, ft_key_pressed_linux, data);
		mlx_hook(data->mlx->win, DestroyNotify, NoEventMask, ft_exit_game, data);
	# endif
	mlx_loop(data->mlx->mlx_ptr);
}
