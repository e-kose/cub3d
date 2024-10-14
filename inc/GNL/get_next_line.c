/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekose <ekose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:20:50 by ekose             #+#    #+#             */
/*   Updated: 2023/11/08 17:35:02 by ekose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

char	*ft_line_read(int fd, char *buf, char *reserv)
{
	int		readed;
	char	*temp;

	readed = 1;
	while (readed)
	{
		readed = read(fd, buf, BUFFER_SIZE);
		if (readed == -1)
			return (NULL);
		else if (readed == 0)
			break ;
		buf[readed] = '\0';
		if (reserv == NULL)
			reserv = ft_strdup("");
		temp = reserv;
		reserv = ft_strjoin(temp, buf);
		if (reserv == NULL)
			return (NULL);
		free(temp);
		temp = NULL;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (reserv);
}

char	*ft_polish(char *line)
{
	int		i;
	char	*cleaned;

	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
		i++;
	if (line[i] == '\0')
		return (NULL);
	cleaned = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (cleaned == NULL)
		return (NULL);
	if (cleaned[0] == '\0')
	{
		free(cleaned);
		cleaned = NULL;
		return (NULL);
	}
	line[i + 1] = '\0';
	return (cleaned);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buf;
	static char	*reserv;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buf = malloc(1 + BUFFER_SIZE);
	if (!buf)
		return (NULL);
	line = ft_line_read(fd, buf, reserv);
	free (buf);
	if (line == NULL)
	{
		free(reserv);
		reserv = NULL;
		return (NULL);
	}
	reserv = ft_polish(line);
	return (line);
}
