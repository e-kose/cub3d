/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekose <ekose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 11:01:01 by ekose             #+#    #+#             */
/*   Updated: 2023/10/23 18:26:37 by ekose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	char	*p;

	i = 0;
	if (!s1)
		return (0);
	if (!set)
		return (ft_strdup(s1));
	j = ft_strlen(s1) - 1;
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	while (s1[i] && ft_strchr(set, s1[j]))
		j--;
	p = ft_substr(s1, i, ((j - i) + 1));
	return (p);
}
