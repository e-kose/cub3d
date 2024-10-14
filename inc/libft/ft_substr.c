/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekose <ekose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 15:09:05 by ekose             #+#    #+#             */
/*   Updated: 2023/10/21 12:16:48 by ekose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char	const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*p;

	if (start > ft_strlen(s))
	{
		return (ft_strdup(""));
	}
	if (ft_strlen(s) < len)
		len = ft_strlen(s);
	i = 0;
	p = malloc((sizeof(char)) * (len + 1));
	if (p == NULL)
		return (NULL);
	while (s[start] && i < len)
	{
		p[i] = s[start];
		i++;
		start++;
	}
	p[i] = '\0';
	return (p);
}
