/*########       ##    ##  #######   ######  ########
##               ##   ##  ##     ## ##    ## ##
##               ##  ##   ##     ## ##       ##
######  #######  #####    ##     ##  ######  ######
##               ##  ##   ##     ##       ## ##
##               ##   ##  ##     ## ##    ## ##
########         ##    ##  #######   ######  ########*/

#include "../inc/cub3d.h"

int	ft_key_released_linux(int keycode, t_data *data)
{

	if (keycode == 119)
		data->key->w = 0;
	if (keycode == 97)
		data->key->a = 0;
	if (keycode == 115)
		data->key->s = 0;
	if (keycode == 100)
		data->key->d = 0;
	if (keycode == 65361)
		data->key->left = 0;
	if (keycode == 65363)
		data->key->right = 0;
	return (0);
}

int	ft_key_pressed_linux(int keycode, t_data *data)
{

	if (keycode == 65307)
		ft_free(data, NULL);
	if (keycode == 119)
		data->key->w = 1;
	if (keycode == 97)
		data->key->a = 1;
	if (keycode == 115)
		data->key->s = 1;
	if (keycode == 100)
		data->key->d = 1;
	if (keycode == 65361)
		data->key->left = 1;
	if (keycode == 65363)
		data->key->right = 1;
	return (0);
}

int	ft_key_released_mac(int keycode, t_data *data)
{
	if (keycode == 13)
		data->key->w = 0;
	if (keycode == 0)
		data->key->a = 0;
	if (keycode == 1)
		data->key->s = 0;
	if (keycode == 2)
		data->key->d = 0;
	if (keycode == 123)
		data->key->left = 0;
	if (keycode == 124)
		data->key->right = 0;
	return (0);
}

int	ft_key_pressed_mac(int keycode, t_data *data)
{
	if (keycode == 53)
		ft_free(data, NULL);
	if (keycode == 13)
		data->key->w = 1;
	if (keycode == 0)
		data->key->a = 1;
	if (keycode == 1)
		data->key->s = 1;
	if (keycode == 2)
		data->key->d = 1;
	if (keycode == 123)
		data->key->left = 1;
	if (keycode == 124)
		data->key->right = 1;
	return (0);
}

void	ft_player_move(t_data *data)
{
	if (data->key->w)
		ft_move_ws(data, 1);
	if (data->key->s)
		ft_move_ws(data, -1);
	if (data->key->a)
		ft_move_ad(data, -1);
	if (data->key->d)
		ft_move_ad(data, 1);
	if (data->key->right)
		ft_rotate_player(data, 1);
	if (data->key->left)
		ft_rotate_player(data, -1);
}
