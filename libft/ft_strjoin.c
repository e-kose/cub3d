/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekose <ekose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 17:14:28 by ekose             #+#    #+#             */
/*   Updated: 2023/10/20 18:51:04 by ekose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	size_t	i;
	int		j;
	char	*p;

	if (!s1 && !s2)
		return (ft_strdup(""));
	len = ft_strlen(s1) + ft_strlen(s2);
	i = 0;
	j = ft_strlen(s1);
	p = malloc(sizeof(char) * (len) + 1);
	if (!p)
		return (0);
	ft_memcpy(p, s1, ft_strlen(s1));
	while (i < ft_strlen(s2))
	{
		p[j++] = s2[i++];
	}
	p[j] = '\0';
	return (p);
}
