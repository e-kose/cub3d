/*########       ##    ##  #######   ######  ########
##               ##   ##  ##     ## ##    ## ##
##               ##  ##   ##     ## ##       ##
######  #######  #####    ##     ##  ######  ######
##               ##  ##   ##     ##       ## ##
##               ##   ##  ##     ## ##    ## ##
########         ##    ##  #######   ######  ########*/

#include "../inc/cub3d.h"

int	ft_exit_game(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	ft_free(data, NULL);
	return (0);
}

void	ft_error_msg(char *s)
{
	ft_putstr_fd(s, 2);
	ft_putstr_fd("\n", 2);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	ft_free_list(t_data *data)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = data->node;
	while (tmp)
	{
		free(tmp->content);
		tmp2 = tmp;
		tmp = tmp->next;
		free(tmp2);
	}
}
