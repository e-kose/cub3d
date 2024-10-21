/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehmyilm <mehmyilm@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 13:16:24 by ekose             #+#    #+#             */
/*   Updated: 2024/10/20 16:22:43 by mehmyilm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CUB3D_H
# define CUB3D_H
# ifdef __linux__
	#include "mlx_linux/mlx.h"
	#define LIB_NAME "Linux Library"
# else
	#include "mlx_mac/mlx.h"
	#define LIB_NAME "Mac Library"
# endif
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft/libft.h"
# include "GNL/get_next_line.h"


typedef struct s_map
{
	char	**map;
	char	**cpymap;
	char	*_1d_map;
	int		map_width;
	int		map_height;
	int		space_count;

}	t_map;
typedef struct s_texture
{
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	char	**floor;
	char	**ceiling;
	int		txt_count[6];
	int		floor_color[3];
	int		ceiling_color[3];
}	t_texture;

typedef struct s_data
{
	t_map 		*map;
	t_texture	*texture;
	t_list		*node;
	char		*argv;
	int			*player;
	char		player_dir;
	int			fd;
}	t_data;


void	ft_error_msg(char *s);
int		ft_strcmp(char *s1, char *s2);
void 	ft_read_map(t_data *data);
void 	ft_parse_map(char *av, t_data *data);
void 	ft_free(t_data *data, char *s);
void	ft_check_line(t_data *data, char *line);
void	ft_fill_space(t_map *map);
void	ft_print_double_str(char **str);
void	ft_flood_fill(int plyr_y, int plyr_x, t_map *map);
void	ft_free_double_str(char **s);
void	ft_check_fill(t_data *data);
void	ft_check_wall(t_data *data, char **map);
// void	ft_take_map(t_list *node, char *line);
#endif
