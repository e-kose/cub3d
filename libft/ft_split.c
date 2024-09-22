/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekose <ekose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 13:55:59 by ekose             #+#    #+#             */
/*   Updated: 2023/11/01 18:24:02 by ekose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_worldlen(const char *s, char c, int start)
{
	int	i;

	i = 0;
	while (s[start] && s[start] != c)
	{
		i++;
		start++;
	}
	return (i);
}

static int	ft_wordcount(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] != '\0')
		{
			count++;
			i++;
		}
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (count);
}

static char	*ft_wordemb(const char *s, char c, int start)
{
	int		len;
	int		i;
	int		j;
	char	*str;

	i = start;
	len = ft_worldlen(s, c, start);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	j = 0;
	while (s[i] != c && s[i] != '\0')
		str[j++] = s[i++];
	str[j] = '\0';
	return (str);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**dest;

	if (!s)
		return (0);
	dest = malloc(sizeof(char *) * (ft_wordcount(s, c) + 1));
	if (!dest)
		return (0);
	i = 0;
	j = -1;
	while (s[i])
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] != '\0')
			dest[++j] = ft_wordemb(s, c, i++);
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	dest[++j] = NULL;
	return (dest);
}
