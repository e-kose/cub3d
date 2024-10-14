/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekose <ekose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 13:16:24 by ekose             #+#    #+#             */
/*   Updated: 2024/10/14 18:26:36 by ekose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CUB3D_H
# define CUB3D_H

# include "mlx/mlx.h"
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
	int		map_width;
	int		map_height;

}	t_map;
typedef struct s_texture
{
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	char 	**floor;
	char 	**ceiling;
	int		txt_count[6];
	int		floor_color[3];
	int		ceiling_color[3];
}	t_texture;

typedef struct s_data
{
	t_map 		*map;
	t_texture	*texture;
	char 		*argv;
	int 		fd;
	
}	t_data;


void	ft_error_msg(char *s);
int		ft_strcmp(char *s1, char *s2);
void 	ft_read_map(t_data *data);
void 	ft_parse_map(char *av, t_data *data);
void 	ft_free(t_data *data, char *s);
#endif