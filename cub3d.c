#include "inc/cub3d.h"
int main(int ac, char **av)
{
	if (ac == 2)
	{
		printf("Hello, %s\n", av[1]);
	}
	else
	{
		printf("Error\n");
	}

	return (0);
}