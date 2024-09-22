/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekose <ekose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 23:13:40 by ekose             #+#    #+#             */
/*   Updated: 2024/09/22 15:03:10 by ekose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

char	*decimal_to_hexadecimal(int decimal)
{
	char	*hexadecimal;
	int		cur;

	if (decimal < 0 || decimal > 255)
		return (NULL);
	hexadecimal = ft_calloc(3, sizeof(char));
	if (!hexadecimal)
		return (NULL);
	ft_memset(hexadecimal, '0', 2);
	cur = 1;
	while (decimal > 0)
	{
		hexadecimal[cur--] = "0123456789ABCDEF"[decimal % 16];
		decimal /= 16;
	}
	return (hexadecimal);
}

int	check_rgb_string_format(char *rgb_string)
{
	int	cur;
	int	comma_count;

	cur = 0;
	comma_count = 0;
	while (rgb_string[cur])
	{
		if (rgb_string[cur] == ',')
		{
			comma_count++;
			if (comma_count > 2)
				return (0);
		}
		else if (rgb_string[cur] == '+')
		{
			if (!ft_isdigit(rgb_string[cur + 1]))
				return (0);
		}
		else if (!ft_isdigit(rgb_string[cur]))
			return (0);
		cur++;
	}
	return (1);
}

char	**rgb_string_to_array(char *rgb)
{
	char	**rgbs;

	if (!check_rgb_string_format(rgb))
	{
		free(rgb);
		printf("Error\n(Invalid RGB color format)\n");
		return (NULL);
	}
	rgbs = ft_split(rgb, ',');
	return (rgbs);
}

char	*rgb_to_hex(char *rgb)
{
	char	*color;
	char	**rgbs;
	char	*temp_hex;
	int		cur;

	color = ft_strdup("");
	rgbs = rgb_string_to_array(rgb);
	if (!rgbs)
		return (free(color), NULL);
	cur = 0;
	while (rgbs[cur])
	{
		if (ft_atoi(rgbs[cur]) > 255 || ft_atoi(rgbs[cur]) < 0)
			return (free_rgb(rgb, rgbs), free(color),
				print_error("Error\n(Color value must be between 0 and 255)\n"));
		temp_hex = decimal_to_hexadecimal(ft_atoi(rgbs[cur++]));
		if (!temp_hex)
			return (free_rgb(rgb, rgbs), free(color), NULL);
		color = ft_strappend(&color, temp_hex);
		if (!color)
			return (free_rgb(rgb, rgbs), free(temp_hex), NULL);
		free(temp_hex);
	}
	return (free_rgb(rgb, rgbs), color);
}
