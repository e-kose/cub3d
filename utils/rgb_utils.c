/*########       ##    ##  #######   ######  ########
##               ##   ##  ##     ## ##    ## ##
##               ##  ##   ##     ## ##       ##
######  #######  #####    ##     ##  ######  ######
##               ##  ##   ##     ##       ## ##
##               ##   ##  ##     ## ##    ## ##
########         ##    ##  #######   ######  ########*/

#include "../inc/cub3d.h"

static void	ft_check_rgb(t_data *data, char **rgb)
{
	int	i;
	int	j;

	i = -1;
	while (rgb[++i])
	{
		j = -1;
		while ((rgb[i][++j]))
		{
			if (!ft_isdigit((rgb[i][j])))
			{
				if (rgb[i][j] == '-')
					ft_free(data, "RGB value must be between 0 and 255");
				if (!((rgb[i][j] >= 9 && rgb[i][j] <= 13) || rgb[i][j] == 32))
					ft_free(data, "RGB value must be digit");
			}
		}
	}
}

char	**ft_clean_rgb(t_data *data, char **str)
{
	int		i;
	char	**tmp;

	i = 0;
	while (str[i])
		i++;
	if (i != 3)
		ft_free(data, "RGB value must be 3");
	i = -1;
	tmp = malloc(sizeof(char *) * 4);
	if (tmp == NULL)
		ft_free(data, "Malloc error");
	while (str[++i])
		tmp[i] = ft_strtrim(str[i], " ");
	tmp[i] = NULL;
	while (--i)
	{
		if (ft_strlen(tmp[i]) == 0)
		{
			ft_free_double_str(tmp);
			ft_free(data, "RGB value must be between 0 and 255");
		}
	}
	ft_free_double_str(str);
	return (tmp);
}

void	ft_convert_rgb(t_data *data, char **rgb, char c)
{
	int	i;

	i = -1;
	ft_check_rgb(data, rgb);
	while (rgb[++i])
	{
		if (ft_atoi(rgb[i]) < 0 || ft_atoi(rgb[i]) > 255)
			ft_free(data, "RGB value must be between 0 and 255");
	}
	if (c == 'F')
		data->texture->floor_color = (ft_atoi(rgb[0]) << 16)
			+ (ft_atoi(rgb[1]) << 8) + ft_atoi(rgb[2]);
	else if (c == 'C')
		data->texture->ceiling_color = (ft_atoi(rgb[0]) << 16)
			+ (ft_atoi(rgb[1]) << 8) + ft_atoi(rgb[2]);
}
