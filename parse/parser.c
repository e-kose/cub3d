/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekose <ekose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 21:43:41 by ekose             #+#    #+#             */
/*   Updated: 2024/09/22 15:09:48 by ekose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	is_map_content_line_correct(char *line)
{
	if (!check_map_line_char(line))
	{
		printf("Error\n(The map content contains invalid characters)\n");
		return (0);
	}
	else if (ft_is_empty(line))
	{
		printf("Error\n(The map content contains empty lines)\n");
		return (0);
	}
	else if (ft_is_only(line, ' '))
	{
		printf("Error\n(The map content contains lines with only spaces)\n");
		return (0);
	}
	else
		return (1);
}

char	*get_map_content(int map_fd, char **line, t_parsed *parsed)
{
	char	*map_line;

	map_line = ft_strdup("");
	while (*line != NULL)
	{
		if (!has_every_data(parsed))
		{
			printf("Error\n(The map does not contain all the textures"
				" and colors information)\n");
			return (free_parsing_el(parsed, &map_line, line, map_fd));
		}
		else if (!is_map_content_line_correct(*line))
			return (free_parsing_el(parsed, &map_line, line, map_fd));
		else
		{
			map_line = ft_strappend(&map_line, *line);
			if (!map_line)
				return (free_parsed(parsed), free(*line),
					free(get_next_line(map_fd, GNL_CLEAR)), NULL);
		}
		free(*line);
		*line = get_next_line(map_fd, GNL_KEEP);
	}
	return (map_line);
}

int	extract_map_values(int map_fd, char **line, t_parsed *parsed)
{
	while (*line != NULL)
	{
		if (!ft_strncmp("NO", *line, 2) || !ft_strncmp("SO", *line, 2)
			|| !ft_strncmp("EA", *line, 2) || !ft_strncmp("WE", *line, 2))
		{
			if (!extract_texture(*line, parsed))
				return (free_parsed(parsed), free(*line),
					free(get_next_line(map_fd, GNL_CLEAR)), 0);
		}
		else if (!ft_strncmp("F", *line, 1) || !ft_strncmp("C", *line, 1))
		{
			if (!extract_color(*line, parsed))
				return (free_parsed(parsed), free(*line),
					free(get_next_line(map_fd, GNL_CLEAR)), 0);
		}
		else if (!ft_is_empty(*line))
			return (1);
		free(*line);
		*line = get_next_line(map_fd, GNL_KEEP);
	}
	return (1);
}

int	check_map_extension(char *file_path)
{
	int		len;

	len = ft_strlen(file_path);
	if (len < 4)
		return (0);
	else if (ft_strncmp(&file_path[len - 4], ".cub", 4))
		return (0);
	else
		return (1);
}

char	*parse_map_file(char *file_path, t_parsed *parsed)
{
	int			map_fd;
	char		*line;
	char		*map_line;

	map_fd = open(file_path, O_RDONLY);
	if (map_fd < 0)
		return (free_parsed(parsed),
			print_error("Error\n(Unable to open the map file)\n"));
	if (!check_map_extension(file_path))
		return (free_parsed(parsed),
			print_error("Error\n(The map file extension is not .cub)\n"));
	line = get_next_line(map_fd, GNL_KEEP);
	if (!extract_map_values(map_fd, &line, parsed))
		return (NULL);
	map_line = get_map_content(map_fd, &line, parsed);
	if (!map_line)
		return (NULL);
	if (!has_every_data(parsed))
		return (free(map_line), free_parsed(parsed),
			print_error("Error\n(The map does not contain all the textures and"
				" colors information)\n"));
	if (ft_strlen(map_line) == 0)
		return (free(map_line), free_parsed(parsed),
			print_error("Error\n(The content of the map is empty)\n"));
	return (map_line);
}
