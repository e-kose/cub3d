/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehmyilm <mehmyilm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 12:43:10 by mehmyilm          #+#    #+#             */
/*   Updated: 2024/10/21 13:16:08 by mehmyilm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

	i = -1;
	tmp = malloc(sizeof(char *) * 4);
	if (tmp == NULL)
		ft_free(data, "Malloc error");
	while (str[++i])
	{
		tmp[i] = ft_strtrim(str[i], " ");
		free(str[i]);
		if (tmp[i] == NULL)
			ft_free(data, "Malloc error");
	}
	tmp[i] = NULL;
	free(str);
	if (i != 3)
		ft_free(data, "RGB value must be 3");
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
	i = -1;
	while (rgb[++i])
	{
		if (c == 'F')
			data->texture->floor_color[i] = ft_atoi(rgb[i]);
		else if (c == 'C')
			data->texture->ceiling_color[i] = ft_atoi(rgb[i]);
	}
}
