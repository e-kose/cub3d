/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekose <ekose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 21:20:32 by ekose             #+#    #+#             */
/*   Updated: 2024/09/22 16:41:54 by ekose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../mlx/mlx.h"
# include "../mlx/improved_mlx.h"
# include "../libft/libft.h"
# include "../GNL/get_next_line.h"
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>

# define PI 	3.1415926535
# define DR 	0.0174533

# define N		0
# define S		1
# define E		2
# define O		3
# define DOOR	4
# define MOUSE_LEFT			1
# define MOUSE_RIGHT		2
# define KEY_ESC			53
# define KEY_LEFT			123
# define KEY_RIGHT			124
# define KEY_Z				13
# define KEY_S				1
# define KEY_Q				0
# define KEY_D				2
# define KEY_M				46
# define KEY_P				35

# define ON_DESTROY			17
# define ON_BUTTON_PRESS	4
# define ON_BUTTON_RELEASE	5
# define ON_MOTION_NOTIFY	6

typedef struct s_parsed	t_parsed;
typedef struct s_pos	t_pos;
typedef struct s_raycasting	t_raycasting;

typedef struct s_image
{
	void		*img;
	char		*addr;
	u_int32_t	**arr;

	int			bits_per_pixel;
	int			line_length;
	int			endian;

	int			widt;
	int			heig;
}					t_image;



typedef struct s_player
{
	int		x;
	int		y;
	char	dir;
}	t_player;

typedef struct s_map2D
{
	char	**map;
	size_t	width;
	size_t	height;
}	t_map2D;

typedef struct s_map1D
{
	int		*map;
	size_t	width;
	size_t	height;
}	t_map1D;

typedef struct s_parsed
{
	char		*north_texture;
	char		*south_texture;
	char		*east_texture;
	char		*west_texture;

	int			floor_color;
	int			ceil_color;

	t_player	player;
	t_map2D		*map2d;
	t_map1D		*map1d;
}	t_parsed;

typedef struct s_pos
{
	float		x;
	float		y;
	float		pdx;
	float		pdy;	
	float		pa;

	int			ipx;
	int			ipx_add_xo;
	int			ipx_sub_xo;
	int			ipy;
	int			ipy_add_yo;
	int			ipy_sub_yo;
	int			ipx_add_px;
	int			ipx_sub_px;
	int			ipy_add_py;
	int			ipy_sub_py;
	float		px;
	float		py;
	int			xo;
	int			yo;
}					t_pos;

typedef struct s_raycasting
{
	int			tmpdir1;
	int			tmpdir2;
	int			dir;

	int			focal;

	float		disv;
	float		dish;
	float		dist;

	float		lineh;
	float		lineo;

	float		atan;
	float		ntan;

	float		ra;
	float		rayx;
	float		rayy;
	float		vertx;
	float		verty;
	float		horix;
	float		horiy;
	float		xo;
	float		yo;
	float		ca;

	float		ratiox;
	float		shade;

	int			mp;
	int			mx;
	int			my;
	int			dow;
}					t_raycasting;

typedef struct cub
{
	void			*mlx;
	void			*mlxwin;

	int				*map;

	int				mapw;
	int				maph;
	int				mapscale;
	int				max;
	int				resizemap;

	int				checkimg;

	int				mouse_grabbed;
	int				display_map;
	int				posx;
	int				posy;

	char			clavier[7];

	t_raycasting	data;
	t_pos			pos;
	t_image			image[3];
	t_image			texture[5];
	t_parsed		*pars;
}					t_cub;

t_parsed	*parse(char *file_path);


void		*free_parsed(t_parsed *map);
int			free_map2d(t_map2D *map2D);
void		*free_parsing_el(t_parsed *map, char **str1, char **str2, int fd);
void		free_rgb(char *rgb_line, char **rgb);


size_t		ft_strlcpy2(char *dst, const char *src, size_t size);
char		*ft_strappend(char **dest, char const *str);
int			ft_is_only(char *line, char c);
int			ft_is_empty(char *line);
int			ft_str_contains(char *str, char c);


char		*decimal_to_hexadecimal(int decimal);
int			check_rgb_string_format(char *rgb_string);
char		*rgb_to_hex(char *rgb);


char		*extract_texture(char *line, t_parsed *map);
void		*extract_color(char *line, t_parsed *map);
char		*get_line_value(int prefix_len, char *line);


char		*print_error(char *error);


t_map2D		*dup_map2d(t_map2D *map2D);
int			get_player(char **map, t_player *player);
size_t		get_map_width(char **map);
size_t		get_map_height(char **map);


char		**parse_map_line(char *map_line);


char		*parse_map_file(char *file_path, t_parsed *parsed);
int			check_map_line_char(char *line);
int			has_every_data(t_parsed *map);


int			check_map(t_parsed *map);
int			count_correct_sides(t_map2D *map2D, size_t x, size_t y);
int			can_exit_map_from_pos(t_map2D *map2D, size_t x, size_t y);

float		dist(float ax, float ay, float bx, float by);
void		ft_final_maths(t_cub *cub);
void		reset_raycasting_varshori(t_cub *cub);
void		reset_raycasting_varsverti(t_cub *cub);
void		fix_angle(t_cub *cub);

void		my_mlx_pixel_put(t_image *image, int x, int y, int color);
void		ft_draw_line(t_cub *cub, t_pos pos, int endx, int endy);

void		ft_putplayer(uint32_t **img_color, t_pos *pos);
void		ft_drawwalls(t_cub *cub, int beginx, int beginy, int lineH);
void		ft_drawsquare(uint32_t **img_color, int posx, int posy, int scale);
void		ft_drawmap(t_cub *cub);
void		ft_draw_font(t_cub *cub);

void		drawrays(t_cub *cub);

u_int32_t	**ft_mem2array(uint32_t *mem, size_t len_x, size_t len_y);
void		init_imagespartone(t_cub *cub, int *i);

void		ft_keyvalidation(t_cub *cub);
int			key_hook_release(int keycode, t_cub *cub);
int			key_hook(int keycode, t_cub *cub);
int			render_next_frame(t_cub *cub);
void		ft_hori(t_cub *cub);
void		ft_hori_try_contact(t_cub *cub);
void		ft_verti(t_cub *cub);
void		ft_verti_try_contact(t_cub *cub);
void		ft_shorter(t_cub *cub);
void		playerdir(t_cub *cub);
void		ft_setmovevalue(t_cub *cub);
void		ft_doormanager(t_cub *cub);
int			parse_only(t_parsed *pars);
int			mouse_motion(int x, int y, t_cub *cub);
int			mouse_release(int key, int x, int y, void *param);
int			destroy(void *param);
int			ft_errorimg_norm(t_cub *cub, int i, mlx_ptr_t *new_mlx);
int			ft_errorimg(t_cub *cub, int i);


#endif