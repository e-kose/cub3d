/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehmyilm <mehmyilm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 13:16:24 by ekose             #+#    #+#             */
/*   Updated: 2024/11/06 16:17:04 by mehmyilm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# ifdef __linux__
#  include "mlx_linux/mlx.h"
#  define LIB_NAME "Linux Library"
#  include <X11/X.h>
# else
#  include "mlx_mac/mlx.h"
#  define LIB_NAME "Mac Library"
# endif
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft/libft.h"
# include "GNL/get_next_line.h"
# define WIDTH 1500
# define HEIGHT 1000
# define RAY_UP 3
# define RAY_DOWN 2
# define RAY_LEFT 0
# define RAY_RIGHT 1

typedef struct s_raycast
{
	double		camera_x;
	double		raydir_x;
	double		raydir_y;
	double		sidedist_x;
	double		sidedist_y;
	double		deltadist_x;
	double		deltadist_y;
	int			step_x;
	int			step_y;
	int			side1;
	int			hit;

	int			tex_x;
	int			tex_y;

	double		perp_dist;
	int			height;
	int			start_y;
	int			end_y;
}	t_raycast;

typedef struct s_key
{
	int	w;
	int	s;
	int	a;
	int	d;
	int	left;
	int	right;
}	t_key;

typedef struct s_player
{
	double		loc_x;
	double		loc_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	int			loc_ipx;
	int			loc_ipy;
}	t_player;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win;
	void	*img;
	int		*addr;
	int		bpp;
	int		line_length;
	int		endian;
}	t_mlx;

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
	int		floor_color;
	int		ceiling_color;
}	t_texture;

typedef struct s_img
{
	void	*img;
	int		*addr;
	int		bpp;
	int		line_length;
	int		endian;
	int		xpm_w;
	int		xpm_h;
}	t_img;

typedef struct s_data
{
	t_map		*map;
	t_texture	*texture;
	t_list		*node;
	t_mlx		*mlx;
	t_player	*player;
	t_img		*img[4];
	t_key		*key;
	t_raycast	*raycast;
	char		*argv;
	int			plyr_loc[2];
	char		player_dir;
	int			fd;
}	t_data;

void	ft_error_msg(char *s);
int		ft_strcmp(char *s1, char *s2);
void	ft_read_map(t_data *data);
void	ft_parse_map(char *av, t_data *data);
void	ft_free(t_data *data, char *s);
void	ft_check_char(t_data *data, char *line);
void	ft_fill_space(t_data *data);
void	ft_flood_fill(int plyr_y, int plyr_x, t_map *map);
void	ft_check_fill(t_data *data, int i, int j);
void	ft_check_space(t_data *data);
void	ft_free_double_str(char **s);
void	ft_check_wall(t_data *data, char **map);
void	ft_take_map(t_list **node, char *line);
int		ft_check_texture_count(t_data *data);
void	ft_take_texture(t_data *data, char *line, int *i);
char	**ft_clean_rgb(t_data *data, char **str);
void	ft_convert_rgb(t_data *data, char **rgb, char c);
void	ft_check_line(t_data *data);
void	ft_init_mlx(t_data *data);
void	ft_check_texture(t_data *data);
int		ft_game_handler(void *param);
void	ft_player_move(t_data *data);
int		ft_key_pressed_mac(int keycode, t_data *data);
int		ft_key_released_mac(int keycode, t_data *data);
void	ft_move_ws(t_data *data, int direction);
void	ft_move_ad(t_data *data, int direction);
void	ft_rotate_player(t_data *data, int direction);
void	ft_init_raycast(t_data *data, int x);
void	ft_calc_side(t_data *data);
int		ft_exit_game(void *data);
void	ft_free_list(t_data *data);
void	ft_dda(t_data *data);
#endif
