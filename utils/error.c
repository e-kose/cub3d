#include "../inc/cub3d.h"

void	ft_error_msg(char *s)
{
	ft_putstr_fd(s, 2);
	ft_putstr_fd("\n", 2);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}
